#ifndef HEALTH_STATUS_H
#define HEALTH_STATUS_H
#include "battery_monitor.h"
#include "temperature.h"


class BatteryChecker {
public:
    BatteryChecker();
    void checkBatteryStatus();

private:
    BatteryMonitor batteryMonitor;
};

#endif
