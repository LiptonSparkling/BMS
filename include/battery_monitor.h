#ifndef BATTERY_MONITOR_H //verhindert Mehrfacheinbindung
#define BATTERY_MONITOR_H

#include <ADC.h>
#include "Wire.h"
#include "SPI.h"
#include "common/mavlink.h"
#include "common/mavlink_msg_battery_status.h"
#include "SD.h"
#include <HardwareSerial.h>


/*
extern const int cell1Pin;
extern const int cell2Pin;
extern const int cell3Pin;

extern const float cell1Divider;
extern const float cell2Divider;
extern const float cell3Divider;

extern const float cell1Calibration;
extern const float cell2Calibration;
extern const float cell3Calibration;

*/

// BATTERY_MONITOR_H
class BatteryMonitor {
public:
  void setup();
  void loop();

private:
  void send_battery_status(float voltage1, float voltage2, float voltage3);
  String getNextLogFileName();
};

#endif 
