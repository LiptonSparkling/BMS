#include "battery_monitor.h"
#include "current.h"
#include "temperature.h"
#include "RFIDReader.h"
#include "display.h"
#include "MavlinkMessages.h"


//Objects
Temperature temp(MAX31865_CS_1, MAX31865_CS_2, MAX31865_CS_3, MAX31865_CS_4, MAX31865_MOSI, MAX31865_MISO, MAX31865_CLK, RTD_REF_RESISTANCE);
CURRENT ampere(AMPERE_PIN);
RFIDReader rfidReader;
extern Display myDisplay;

// Define Batterytype -> Choose for MAVLink
int Batterytype = 1;
//0 = Type unknown
//1 = LiPo
//2 = LiFe
//3 = LiIon
//4 = NiMh

// Voltage divider constants
const float R1 = 10000.0;
const float R2 = 2983.0;
const float R3 = 10000.0;
const float R4 = 15920.0;
const float R5 = 9910.0;
const float R6 = 29600.0;

// Define Analog inputs
const int cell1Pin = A0;
const int cell2Pin = A1;
const int cell3Pin = A2;

// Calibration constants for cell voltages
const float cell1Calibration = 1.007696007696008;
const float cell2Calibration = 1.007050;
const float cell3Calibration = 1.007310;

// Voltage divider calculations
const float Vref = 3.3;
const float cell1Divider = (R1 + R2) / R1;
const float cell2Divider = (R3 + R4) / R3;
const float cell3Divider = (R5 + R6) / R5;

// Define the average filter size
const int filterSize = 1;

// Arrays to store previous voltage readings and indices for the moving average filter
float voltages0[filterSize] = {0};
float voltages1[filterSize] = {0};
float voltages2[filterSize] = {0};
int cellIndex = 0;

// LED activation and logging
const int chipSelect = BUILTIN_SDCARD;
bool loggingActive = false;
bool sdCardConnected = true;
const int ledPin = 13;
char logFileNameChar[20];
const float voltageThreshold = 2.0; //Logging Threshold


ADC *adc = new ADC();
File logFile;

  String BatteryMonitor::getNextLogFileName() {
  uint16_t fileNumber = 0;
  String fileName;
  char fileNameChar[20];

  while (true) {
    fileName = "log" + String(fileNumber) + ".csv";
    fileName.toCharArray(fileNameChar, sizeof(fileNameChar));

    if (!SD.exists(fileNameChar)) {
      break;
    }
    fileNumber++;
  }

  return fileName;
}


// Calculating Charge State -> Noch verbuggt
float BatteryMonitor::calculate_Charge_state(float totalVoltage) {
    float cellVoltageAverage = totalVoltage / 3.0;
    float chargeState;
    float cellVoltageMax = 4.2;
    float cellVoltageMin = 3.0;
    float percentageMax = 100.0;
    float percentageMin = 0.0;
    float remaining = 100.0 - chargeState;
    // Constrain the chargeState between 0 and 100
    chargeState = constrain(chargeState, 0, 100);

    return chargeState;
}


void BatteryMonitor::setup() {
  Serial2.begin(57600);
  Serial.begin(9600);


  myDisplay.init();
  rfidReader.initialize();
  RFIDReader::RFIDData data = rfidReader.readCard();
  myDisplay.showRFIDData(data);

  // Cellpins
  pinMode(cell1Pin, INPUT);
  pinMode(cell2Pin, INPUT);
  pinMode(cell3Pin, INPUT);
  pinMode(ledPin, OUTPUT); //LED onboard on Teensy for logging

   // Initialize temp sensors
  temp.begin();

  // ADC configuration
  adc->adc0->setAveraging(4); // Mittelung auf 4 Messungen einstellen
  adc->adc0->setResolution(12); // Auflösung auf 12 Bit einstellen während eine 12-Bit-Auflösung 4096 mögliche digitale Werte (2^12) ergibt. Der Teensy 4.0 unterstützt eine ADC-Auflösung von bis zu 12 Bit, was eine größere Genauigkeit und Empfindlichkeit in der Messung ermöglicht.
  adc->adc0->setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED);
  adc->adc0->setSamplingSpeed(ADC_SAMPLING_SPEED::HIGH_SPEED);
  adc->adc0->setReference(ADC_REFERENCE::REF_3V3); // Referenzspannung auf 3,3V einstellen


  ///Logging
  // SD card initialization
  if (!SD.begin(chipSelect)) {
    Serial.print("SD card initialization failed!");
    Serial.println("NO SD CARD");
    sdCardConnected = false;
  } else {
    Serial.println("SD card initialized.");
  }

  // Find the next available log file name
  String logFileName = getNextLogFileName();
  Serial.print("Log file name: ");
  Serial.println(logFileName);
  logFileName.toCharArray(logFileNameChar, sizeof(logFileNameChar));

  // Create or open the log file
  logFile = SD.open(logFileNameChar, FILE_WRITE);
  if (!logFile) {
    Serial.println("Error opening log file");
  } else {
  // Write the header of the log file
    logFile.print("Timestamp (s),Cell 1 (V),Cell 2 (V),Cell 3 (V),Total Voltage (V),Current (A), Temp Sensor 1 (°C),Temp Sensor 2 (°C),Temp Sensor 3 (°C)");
    logFile.close(); // Close the log file after writing the header
  }

  //Initialize display
  //myDisplay.init();

}


void BatteryMonitor::loop() {

  //Reading voltages
  currentStateRaw.voltages[0] = (adc->adc0->analogRead(cell1Pin) * Vref / 4095.0) * cell1Divider * cell1Calibration;
  currentStateRaw.voltages[1] = (adc->adc0->analogRead(cell2Pin) * Vref / 4095.0) * cell2Divider * cell2Calibration - currentStateRaw.voltages[0];
  currentStateRaw.voltages[2] = (adc->adc0->analogRead(cell3Pin) * Vref / 4095.0) * cell3Divider * cell3Calibration - currentStateRaw.voltages[0] - currentStateRaw.voltages[1];
  currentStateRaw.totalVoltage = currentStateRaw.voltages[0] + currentStateRaw.voltages[1] + currentStateRaw.voltages[2]; // Total voltage calculation and output message

  // Calculating Charge State
  currentStateRaw.chargeState = calculate_Charge_state(currentStateRaw.totalVoltage);

  //Serial print of current
  currentStateRaw.current = ampere.read();
    // Apply current correction
  if (currentStateRaw.current >= 24.0) {
    currentStateRaw.current = currentStateRaw.current -0.68;
  }
  //else if (currentStateRaw.current >= 30.0) {
 //   currentStateRaw.current = currentStateRaw.current * 0.94;
 // }


  Serial.print("Strom: ");
  Serial.print(currentStateRaw.current);
  Serial.println(" A");

  // Read temperature from sensor 1
  currentStateRaw.temperatures[0] = temp.getTemperature(1, RTD_NOMINAL_1);
  if (currentStateRaw.temperatures[0] == -9999.0) {
    Serial.println("Error reading temperature from sensor 1.");
  } else {
    Serial.print("Temperature 1: ");
    Serial.println(currentStateRaw.temperatures[0]);
  }

  // Read temperature from sensor 2
  currentStateRaw.temperatures[1] = temp.getTemperature(2, RTD_NOMINAL_2);
  if (currentStateRaw.temperatures[1] == -9999.0) {
    Serial.println("Error reading temperature from sensor 2.");
  } else {
    Serial.print("Temperature 2: ");
    Serial.println(currentStateRaw.temperatures[1]);
  }

  // Read temperature from sensor 3
  currentStateRaw.temperatures[2] = temp.getTemperature(3, RTD_NOMINAL_3);
  if (currentStateRaw.temperatures[2] == -9999.0) {
    Serial.println("Error reading temperature from sensor 3.");
  } else {
    Serial.print("Temperature 3: ");
    Serial.println(currentStateRaw.temperatures[2]);
  }

  // Read temperature from sensor 4
  currentStateRaw.temperatures[3] = temp.getTemperature(4, RTD_NOMINAL_4);
  if (currentStateRaw.temperatures[3] == -9999.0) {
  Serial.println("Error reading temperature from sensor 4.");
  } else {
  Serial.print("Temperature 4: ");
  Serial.println(currentStateRaw.temperatures[3]);
}

  currentStateFiltered = filter(currentStateRaw);

  // Write data to the log file
  if (currentStateFiltered.voltages[0] > voltageThreshold || currentStateFiltered.voltages[1] > voltageThreshold || currentStateFiltered.voltages[2] > voltageThreshold) {
    loggingActive = true;
  } else {
    loggingActive = false;
  }
  if (sdCardConnected) {
    logFile = SD.open(logFileNameChar, FILE_WRITE);
    if (logFile) {
      logFile.print(millis() / 1000.0, 2);
      logFile.print(", ");
      logFile.print(currentStateFiltered.voltages[0], 3);
      logFile.print(", ");
      logFile.print(currentStateFiltered.voltages[1], 3);
      logFile.print(", ");
      logFile.print(currentStateFiltered.voltages[2], 3);
      logFile.print(",");
      logFile.print(currentStateFiltered.totalVoltage, 2);
      logFile.print(",");
      logFile.print(currentStateFiltered.current, 2);
      logFile.print(",");
      logFile.print(currentStateFiltered.temperatures[0], 2);
      logFile.print(",");
      logFile.print(currentStateFiltered.temperatures[1], 2);
      logFile.print(",");
      logFile.print(currentStateFiltered.temperatures[2], 2);
      logFile.print(",");
      logFile.println(currentStateFiltered.temperatures[3], 2);
      logFile.println();
      logFile.close();
    } else {
      Serial.println("Error opening log file");
    }
  }

  // Toggle LED to indicate logging status
  if (loggingActive && sdCardConnected) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }


 // Mavlink message send cell voltages
  MavlinkMessages::send_battery_status(currentStateFiltered);

  //Display print of voltage values
  myDisplay.Output(currentStateFiltered);

  checker.checkBatteryStatus(currentStateFiltered);

}

BatteryState BatteryMonitor::filter(const BatteryState& raw)
{
  // Initialize filtered state
  BatteryState filtered = raw;

  // Moving average filter for cell voltages
  voltages0[cellIndex] = raw.voltages[0];
  voltages1[cellIndex] = raw.voltages[1];
  voltages2[cellIndex] = raw.voltages[2];

  filtered.voltages[0] = 0;
  filtered.voltages[1] = 0;
  filtered.voltages[2] = 0;

  for (int i = 0; i < filterSize; i++) {
    filtered.voltages[0] += voltages0[i];
    filtered.voltages[1] += voltages1[i];
    filtered.voltages[2] += voltages2[i];
  }

  filtered.voltages[0] /= filterSize;
  filtered.voltages[1] /= filterSize;
  filtered.voltages[2] /= filterSize;

  // Increment pointers to buffer
  cellIndex = (cellIndex + 1) % filterSize;

  return filtered;
}