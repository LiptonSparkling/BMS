#include "battery_monitor.h"
#include "current.h"
#include "temperature.h"
#include "RFIDReader.h"
#include "display.h"
#include "MavlinkMessages.h"

//Objects
Temperature temp(MAX31865_CS_1, MAX31865_CS_2, MAX31865_CS_3, MAX31865_MOSI, MAX31865_MISO, MAX31865_CLK, RTD_REF_RESISTANCE);
RFIDReader rfidReader(SS_PIN, RST_PIN);
CURRENT ampere(AMPERE_PIN);
MavlinkMessages mavlinkHandler; // Create an instance of the MavlinkHandler class

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
const float cell2Calibration = 1.009200;
const float cell3Calibration = 1.013010;

// Voltage divider calculations
const float Vref = 3.3;
const float cell1Divider = (R1 + R2) / R1;
const float cell2Divider = (R3 + R4) / R3;
const float cell3Divider = (R5 + R6) / R5;

// Define the average filter size
const int filterSize = 1;

// Arrays to store previous voltage readings and indices for the moving average filter
float cell1Voltages[filterSize] = {0};
float cell2Voltages[filterSize] = {0};
float cell3Voltages[filterSize] = {0};
int cell1Index = 0;
int cell2Index = 0;
int cell3Index = 0;

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

/*

void BatteryMonitor::send_battery_status(float voltage1, float voltage2, float voltage3) {
 
 //Serial print of Batterystatus
  Serial.print("Sending Battery Status: Cell1 = ");
  Serial.print(voltage1, 3);
  Serial.print("V, Cell2 = ");
  Serial.print(voltage2, 3);
  Serial.print("V, Cell3 = ");
  Serial.println(voltage3, 3);

  float totalVoltage = voltage1 + voltage2 + voltage3;
  
  // Calculate charge_state
  float cellVoltageAverage = totalVoltage / 3.0;
  float chargeState;
  float cellVoltageMax = 4.2;
  float cellVoltageMin = 3.0;
  float percentageMax = 100.0;
  float percentageMin = 0.0;

  if (cellVoltageAverage >= 3.7) {
    chargeState = map(cellVoltageAverage, 3.7, cellVoltageMax, 20, percentageMax);
  } else {
    chargeState = map(cellVoltageAverage, cellVoltageMin, 3.7, percentageMin, 20);
  }

*/
/*
  // Constrain the chargeState between 0 and 100
  chargeState = constrain(chargeState, 0, 100);

  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  uint16_t voltages[10] = {voltage1 * 1000, voltage2 * 1000, voltage3 * 1000, 0, 0, 0, 0, 0, 0, 0}; //Mavlink needs voltage in mA
  mavlink_msg_battery_status_pack(1, 200, &msg, 0, 0, Batterytype, INT16_MIN, voltages, -1, -1, -1, -1, -1, chargeState);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  Serial2.write(buf, len); //send over serial 2 
  
}
*/


void BatteryMonitor::setup() {
  Serial2.begin(57600);
  Serial.begin(9600);
  rfidReader.begin();

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
  myDisplay.init();
  
}


void BatteryMonitor::loop() {

  //Reading voltages
  float cell1Voltage = (adc->adc0->analogRead(cell1Pin) * Vref / 4095.0) * cell1Divider * cell1Calibration;
  float cell2Voltage = (adc->adc0->analogRead(cell2Pin) * Vref / 4095.0) * cell2Divider * cell2Calibration - cell1Voltage;
  float cell3Voltage = (adc->adc0->analogRead(cell3Pin) * Vref / 4095.0) * cell3Divider * cell3Calibration - cell1Voltage - cell2Voltage;
  float totalVoltage = cell1Voltage + cell2Voltage + cell3Voltage; // Total voltage calculation and output message


  //Serial print of current
  float current = ampere.read();
  Serial.print("Strom: ");
  Serial.print(current);
  Serial.println(" A");
  
  //variables for temp 1,2,3
  float temperature_1, temperature_2, temperature_3;

  // Read temperature from sensor 1
  temperature_1 = temp.getTemperature(1, RTD_NOMINAL_1);
  if (temperature_1 == -9999.0) {
    Serial.println("Error reading temperature from sensor 1.");
  } else {
    Serial.print("Temperature 1: ");
    Serial.println(temperature_1);
  }
  
  // Read temperature from sensor 2
  temperature_2 = temp.getTemperature(2, RTD_NOMINAL_2);
  if (temperature_2 == -9999.0) {
    Serial.println("Error reading temperature from sensor 2.");
  } else {
    Serial.print("Temperature 2: ");
    Serial.println(temperature_2);
  }
  
  // Read temperature from sensor 3
  temperature_3 = temp.getTemperature(3, RTD_NOMINAL_3);
  if (temperature_3 == -9999.0) {
    Serial.println("Error reading temperature from sensor 3.");
  } else {
    Serial.print("Temperature 3: ");
    Serial.println(temperature_3);
  }


  // Moving average filter for cell voltages
  cell1Voltages[cell1Index] = cell1Voltage;
  cell2Voltages[cell2Index] = cell2Voltage;
  cell3Voltages[cell3Index] = cell3Voltage;

  float cell1Filtered = 0;
  float cell2Filtered = 0;
  float cell3Filtered = 0;

  for (int i = 0; i < filterSize; i++) {
    cell1Filtered += cell1Voltages[i];
    cell2Filtered += cell2Voltages[i];
    cell3Filtered += cell3Voltages[i];
  }

  cell1Filtered /= filterSize;
  cell2Filtered /= filterSize;
  cell3Filtered /= filterSize;

  cell1Index = (cell1Index + 1) % filterSize;
  cell2Index = (cell2Index + 1) % filterSize;
  cell3Index = (cell3Index + 1) % filterSize;

  cell1Voltage = cell1Filtered;
  cell2Voltage = cell2Filtered;
  cell3Voltage = cell3Filtered;

  // Write data to the log file
  if (cell1Voltage > voltageThreshold || cell2Voltage > voltageThreshold || cell3Voltage > voltageThreshold) {
    loggingActive = true;
  } else {
    loggingActive = false;
  }
  if (sdCardConnected) {
    logFile = SD.open(logFileNameChar, FILE_WRITE);
    if (logFile) {
      logFile.print(millis() / 1000.0, 2);
      logFile.print(", ");
      logFile.print(cell1Voltage, 3);
      logFile.print(", ");
      logFile.print(cell2Voltage, 3);
      logFile.print(", ");
      logFile.print(cell3Voltage, 3);
      logFile.print(",");
      logFile.print(totalVoltage, 2);
      logFile.print(",");
      logFile.print(current, 2);
      logFile.print(",");
      logFile.print(temperature_1, 2);
      logFile.print(",");
      logFile.print(temperature_2, 2);
      logFile.print(",");
      logFile.println(temperature_3, 2);
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
  mavlinkHandler.send_battery_status(cell1Voltage, cell2Voltage, cell3Voltage); // Call the send_battery_status method

  //Display print of voltage values
  myDisplay.Output(totalVoltage, current, temperature_1);


  // Mavlink message send cell voltages
  //send_battery_status(cell1Voltage, cell2Voltage, cell3Voltage);

  //Display print of voltage values
  //myDisplay.Output(totalVoltage, current, temperature_1);

  //delay(1000); // Wait for 1 second

}