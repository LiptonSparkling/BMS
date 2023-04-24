//#include <Arduino.h>
#include "battery_monitor.h"
#include "RFIDReader.h"

BatteryMonitor batteryMonitor;

void setup() {
  batteryMonitor.setup();
}

void loop() {
  batteryMonitor.loop();
}