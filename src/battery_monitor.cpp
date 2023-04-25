#include "battery_monitor.h"
#include "RFIDReader.h"
#include "display.h"

#define RST_PIN 9
#define SS_PIN  10


extern Display myDisplay; //Instanz der Displayklasse namens myDisplay erstellen extern without defining
const int chipSelect = BUILTIN_SDCARD;

RFIDReader rfidReader(SS_PIN, RST_PIN);

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
const float cell2Calibration = 1.009710;
const float cell3Calibration = 1.014010;

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

// Currentsensor
const int currentSensorPin = A5;
const float ACS712_OFFSET = 2.62; //set to offset from manifacturer
float readCurrent(int pin, float sensitivity);

// LED activation and logging
bool loggingActive = false;
bool sdCardConnected = true;
const int ledPin = 13;
char logFileNameChar[20];
const float voltageThreshold = 2.0; //Logging Threshold

ADC *adc = new ADC();
File logFile;

//Reading current
  float readCurrent(int pin, float sensitivity) {
  float voltage = (adc->adc0->analogRead(pin) * Vref / 4095.0);
  float current = (voltage - ACS712_OFFSET) / sensitivity;
  return current;
  }

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

void BatteryMonitor::send_battery_status(float voltage1, float voltage2, float voltage3) {
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

  // Constrain chargeState between 0 and 100
  chargeState = constrain(chargeState, 0, 100);

  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];

  uint16_t voltages[10] = {voltage1 * 1000, voltage2 * 1000, voltage3 * 1000, 0, 0, 0, 0, 0, 0, 0}; //Mavlink needs voltage in mA
  mavlink_msg_battery_status_pack(1, 200, &msg, 0, 0, 0, INT16_MIN, voltages, -1, -1, -1, -1, -1, chargeState);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  Serial2.write(buf, len);
}

void BatteryMonitor::setup() {
  Serial2.begin(57600);
  Serial.begin(9600);
  rfidReader.begin();

  // Cellpins  
  pinMode(cell1Pin, INPUT);
  pinMode(cell2Pin, INPUT);
  pinMode(cell3Pin, INPUT);

  // Currentpins 
  pinMode(currentSensorPin, INPUT);

  //LED on Teensy for logging
  pinMode(ledPin, OUTPUT); //LED pin as output

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
    logFile.println("Timestamp (s),Cell 1 (V),Cell 2 (V),Cell 3 (V),Total Voltage (V)");
    logFile.close(); // Close the log file after writing the header
  }

  //Display initaliseren -> insert
  
}



void BatteryMonitor::loop() {

  //Reading voltages
  float cell1Voltage = (adc->adc0->analogRead(cell1Pin) * Vref / 4095.0) * cell1Divider * cell1Calibration;
  float cell2Voltage = (adc->adc0->analogRead(cell2Pin) * Vref / 4095.0) * cell2Divider * cell2Calibration - cell1Voltage;
  float cell3Voltage = (adc->adc0->analogRead(cell3Pin) * Vref / 4095.0) * cell3Divider * cell3Calibration - cell1Voltage - cell2Voltage;
  float totalVoltage = cell1Voltage + cell2Voltage + cell3Voltage; // Total voltage calculation and output message

 //Serial print of voltages
  Serial.print("Cell 1: ");
  Serial.print(cell1Voltage, 3);
  Serial.print("V, Cell 2: ");
  Serial.print(cell2Voltage, 3);
  Serial.print("V, Cell 3: ");
  Serial.print(cell3Voltage, 3);
  Serial.print(" Total Voltage: ");
  Serial.print(totalVoltage, 2);
  Serial.println("V");
  
  //Display print of voltage values
  myDisplay.init();


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

   // Current reading printing
  float current = readCurrent(currentSensorPin, 0.066 ); // Ersetzen Sie 0.185 durch die Sensitivität Ihres Sensors
  Serial.print("Strom: ");
  Serial.print(current, 2);
  Serial.println(" A");

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
  send_battery_status(cell1Voltage, cell2Voltage, cell3Voltage);


  /*
  
  readCard
    if (rfidReader.readCard()) {
    Serial.print("Serial Number: ");
    Serial.println(rfidReader.getSerialNumber());
    Serial.print("Capacity: ");
    Serial.println(rfidReader.getCapacity());
    Serial.print("Number of Cells: ");
    Serial.println(rfidReader.getNumCells());
    Serial.print("Cell Voltage: ");
    Serial.println(rfidReader.getCellVoltage(), 2);
    Serial.print("Max Capacity Percent: ");
    Serial.println(rfidReader.getMaxCapacityPercent());
  }

*/
  delay(1000); // Wait for 1 second

}
