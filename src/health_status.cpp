#include "health_status.h"
#include "MavlinkMessages.h"


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
            //Mavlink Error senden
            MavlinkMessages::send_status_text(MAV_SEVERITY_ERROR, "Cell Voltage Error!");
            break;
        case 0:
        default:
            // Alles in Ordnung
            ;
    }
}