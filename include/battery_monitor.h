#ifndef BATTERY_MONITOR_H 
#define BATTERY_MONITOR_H

#include <ADC.h>
#include "Wire.h"
#include "SPI.h"
#include "common/mavlink.h"
#include "common/mavlink_msg_battery_status.h"
#include "SD.h"
#include <HardwareSerial.h>

template <unsigned int Cells>
struct BatteryState {
  float voltages[Cells];
  float totalVoltage;
  float chargeState;
  float current;
  float temperatures[Cells + 1];
}

class BatteryMonitor {
public:
  void setup();
  void loop();
  float calculate_Charge_state(float totalVoltage);

private:
  String getNextLogFileName();
  BatteryState<3> filter(const BatteryState<3>& state);
  BatteryState<3> currentStateRaw;
  BatteryState<3> currentStateFiltered;
};

#endif 
