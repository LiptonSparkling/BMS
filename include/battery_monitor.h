#ifndef BATTERY_MONITOR_H 
#define BATTERY_MONITOR_H

#include <ADC.h>
#include "Wire.h"
#include "SPI.h"
#include "common/mavlink.h"
#include "common/mavlink_msg_battery_status.h"
#include "SD.h"
#include <HardwareSerial.h>

class BatteryMonitor {
public:
  void setup();
  void loop();

private:
  void send_battery_status(float voltage1, float voltage2, float voltage3);
  String getNextLogFileName();
};

#endif 
