#include "health_status.h"
#include "battery_monitor.h"

BatteryChecker::BatteryChecker()
{
    memory = LOLA_SPEC::init();
}

void BatteryChecker::checkBatteryStatus(const BatteryState& state)
{
    LOLA_SPEC::Event e = (LOLA_SPEC::Event) {state.voltages[0], state.voltages[1], state.voltages[2]};

    switch(LOLA_SPEC::monitor(&memory, e, 1.0)) {
        case 1:
            // Error: Voltage deviation
            // ... Error message ausgeben oder so
            break;
        case 0:
        default:
            // Alles in Ordnung
            ;
    }
}
