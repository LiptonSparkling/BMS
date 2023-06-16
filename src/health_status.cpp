#include "health_status.h"
#include "battery_monitor.h"

BatteryChecker::BatteryChecker()
{
    memory = lola_init();
}

void BatteryChecker::checkBatteryStatus(const BatteryState& state)
{
    Event e = (Event) {state.voltages[0], state.voltages[1], state.voltages[2]};

    switch(lola_monitor(&memory, e, 1.0)) {
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
