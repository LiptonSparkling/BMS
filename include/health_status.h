#ifndef HEALTH_STATUS_H
#define HEALTH_STATUS_H

struct BatteryState;

#include <Arduino.h>
namespace LOLA_SPEC {
    #include "lola_spec.c"
}

class BatteryChecker
{
    public:
    BatteryChecker();
    void checkBatteryStatus(const BatteryState& state);

    private:
    LOLA_SPEC::Memory memory;
};

#endif
