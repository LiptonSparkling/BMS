#include "health_status.h"
#include "MavlinkMessages.h"


BatteryChecker::BatteryChecker()
{
    memory = lola_init();
}

void BatteryChecker::checkBatteryStatus(const BatteryState& state)
{
    float t = millis() / 1000.0f;
    Event e = (Event) {state.current,
                       state.temperatures[0], state.temperatures[1], state.temperatures[2], state.temperatures[3],
                       state.voltages[0], state.voltages[1], state.voltages[2]};
    TriggerResults res = lola_monitor(&memory, e, t);

    if (res.trigger0 == 1) {
            // Error: Voltage deviation
            Serial.println("Cellvoltage drift!");
            Serial.println("Error triggered by RTLola");
            //Mavlink Error senden
            MavlinkMessages::send_status_text(MAV_SEVERITY_ERROR, "Cell Voltage Error!");
    }
    if (res.trigger1 == 1) {
            // Error: Voltage too low
            Serial.println("Cell voltage below 3.0V!");
            Serial.println("Error triggered by RTLola");
            //Mavlink Error senden
            MavlinkMessages::send_status_text(MAV_SEVERITY_ERROR, "Deep Discharge!");
    }
    if (res.trigger2 == 1) {
            // Error: Voltage deviation
            Serial.println("Over Current (45A)!");
            Serial.println("Error triggered by RTLola");
            //Mavlink Error senden
            MavlinkMessages::send_status_text(MAV_SEVERITY_ERROR, "Over Current Error!");
    }
    if (res.trigger3 == 1) {
            // Error: Voltage deviation
            Serial.println("Max Consumption (3Ah) Reached!");
            Serial.println("Error triggered by RTLola");
            //Mavlink Error senden
            MavlinkMessages::send_status_text(MAV_SEVERITY_ERROR, "Max Consumption Reached!");
    }
    if (res.trigger4 == 1) {
            // Error: Voltage deviation
            Serial.println("Over Temperature!");
            Serial.println("Error triggered by RTLola");
            //Mavlink Error senden
            MavlinkMessages::send_status_text(MAV_SEVERITY_ERROR, "Over Temperature Error!");
    }
}
