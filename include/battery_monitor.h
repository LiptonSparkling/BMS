#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <ADC.h>
#include "Wire.h"
#include "SPI.h"
#include "common/mavlink.h"
#include "common/mavlink_msg_battery_status.h"
#include "SD.h"
#include <HardwareSerial.h>
#include "health_status.h"

/*
template <unsigned int Cells>
*/
struct BatteryState {
  float voltages[3];
  float totalVoltage;
  float chargeState;
  float current;
  float temperatures[3 + 1];
};

class BatteryMonitor {
public:
  void setup();
  void loop();
  float calculate_Charge_state(float totalVoltage);

private:
  String getNextLogFileName();
  BatteryState filter(const BatteryState& state);
  BatteryState currentStateRaw;
  BatteryState currentStateFiltered;
  BatteryChecker checker;
};

#endif
