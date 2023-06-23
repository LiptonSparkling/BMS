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
            send_status_text(MAV_SEVERITY_ERROR, "Cell Voltage Error!");
            break;
        case 0:
        default:
            // Alles in Ordnung
            ;
    }
}


void BatteryChecker::send_status_text(uint8_t severity, const char* text) {
    MavlinkMessages mavlinkMessages;  // Create an instance of the MavlinkMessages class
    mavlinkMessages.send_status_text(severity, text);  // Call the send_status_text function from MavlinkMessages
}