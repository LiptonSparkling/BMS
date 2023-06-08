#ifndef HEALTH_STATUS_H
#define HEALTH_STATUS_H
#include "battery_monitor.h"

#define fprintf(x) // Disable fprintf in LOLA code
namespace LOLA_SPEC {
    #include lola_spec.c
}
#undef fprintf

class BatteryChecker
{
    public:
    BatteryChecker();
    void checkBatteryStatus(const BatteryState<3>& state);

    private:
    LOLA_SPEC::Memory memory;
};

#endif
