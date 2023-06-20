#include "health_status.h"
#include "battery_monitor.h"
#include "common/mavlink.h"
#include "common/mavlink_msg_high_latency2.h"


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
            Serial.println("Cellvoltage drift!");
            Serial.println("Error triggered by RTLola");

            //MAV_BATTERY_FAULT 
            //MAV_BATTERY_FAULT_CELL_FAIL -> One or more cells have failed. Battery should also report MAV_BATTERY_CHARGE_STATE_FAILE (and should not be used).

            break;
        case 0:
        default:
            // Alles in Ordnung
            ;
    }
}
