#include "MavlinkMessages.h"
#include <Arduino.h>
#include "battery_monitor.h"
#include "common/mavlink.h"

Temperature temperatureSensor(MAX31865_CS_1, MAX31865_CS_2, MAX31865_CS_3, MAX31865_CS_4, MAX31865_MOSI, MAX31865_MISO, MAX31865_CLK, RTD_REF_RESISTANCE);
CURRENT amperevalue;

void MavlinkMessages::send_battery_status(const BatteryState& state) {
    //Serial print of Batterystatus
    Serial.print("Sending Battery Status: Cell1 = ");
    Serial.print(state.voltages[0], 3);
    Serial.print("V, Cell2 = ");
    Serial.print(state.voltages[1], 3);
    Serial.print("V, Cell3 = ");
    Serial.println(state.voltages[2], 3);

    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    //Mavlink needs voltage in mA!! Static Cast -> Typeumwandlung gewzungen
    uint16_t voltages[10] = {static_cast<uint16_t>(state.voltages[0] * 1000), static_cast<uint16_t>(state.voltages[1] * 1000), static_cast<uint16_t>(state.voltages[2] * 1000), 0, 0, 0, 0, 0, 0, 0};

    // Integriere die höchste Temperatur in die MAVLink-Nachricht
    uint16_t highestTemp = static_cast<uint16_t>(fmax(state.temperatures[0], fmax(state.temperatures[1], fmax(state.temperatures[2], state.temperatures[3]))) * 100);

    // Remaining bearbeiten und chargestate!
    mavlink_msg_battery_status_pack(1, 200, &msg, 0, 0, Batterytype, highestTemp, voltages, state.current, -1, -1, -1, -1, state.chargeState);

    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

    
    Serial2.write(buf, len);
}


void MavlinkMessages::send_status_text(uint8_t severity, const char* text) {
    mavlink_message_t msg;
    mavlink_statustext_t status_text_msg;

    status_text_msg.severity = severity;
    strncpy(status_text_msg.text, text, sizeof(status_text_msg.text) - 1);
    status_text_msg.text[sizeof(status_text_msg.text) - 1] = '\0';  // Ensure null-termination of the text

    mavlink_msg_statustext_encode(1, 200, &msg, &status_text_msg);

    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

   // Send MavLink Message over serial 2!
    Serial2.write(buf, len);
}



