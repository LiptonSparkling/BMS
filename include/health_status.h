#ifndef HEALTH_STATUS_H
#define HEALTH_STATUS_H

struct BatteryState;

#include <Arduino.h>

extern "C" {
    #include "lola_spec.h"
}

class BatteryChecker
{
    public:
    BatteryChecker();
    void checkBatteryStatus(const BatteryState& state);

    private:
    Memory memory;
};

#endif
