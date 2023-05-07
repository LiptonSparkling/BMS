//#include <Arduino.h>
#include "battery_monitor.h"

BatteryMonitor batteryMonitor;

void setup() {
  batteryMonitor.setup();
}

void loop() {
  batteryMonitor.loop();
}