#include "logging.h"

Logging loggfile;


 void Logging::loggingsetup() {

    // LED activation and logging
    pinMode(ledPin, OUTPUT); //LED pin as output

    //setting logging parameters

    bool loggingActive = false;
    bool sdCardConnected = true;
    char logFileNameChar[20];
    const float voltageThreshold = 2.0; //Logging Threshold

    ADC *adc = new ADC();
    File logFile;

/*
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

*/

}



  void Logging::logging(){
 //write the logfiles


}