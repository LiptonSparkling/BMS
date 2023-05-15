#include "MavlinkMessages.h"
#include <Arduino.h>


void MavlinkMessages::send_battery_status(float voltage1, float voltage2, float voltage3) {
    //Serial print of Batterystatus
    Serial.print("Sending Battery Status: Cell1 = ");
    Serial.print(voltage1, 3);
    Serial.print("V, Cell2 = ");
    Serial.print(voltage2, 3);
    Serial.print("V, Cell3 = ");
    Serial.println(voltage3, 3);

    float totalVoltage = voltage1 + voltage2 + voltage3;

    // Calculate charge_state
    float cellVoltageAverage = totalVoltage / 3.0;
    float chargeState;
    float cellVoltageMax = 4.2;
    float cellVoltageMin = 3.0;
    float percentageMax = 100.0;
    float percentageMin = 0.0;

    if (cellVoltageAverage >= 3.7) {
        chargeState = map(cellVoltageAverage, 3.7, cellVoltageMax, 20, percentageMax);
    } else {
        chargeState = map(cellVoltageAverage, cellVoltageMin, 3.7, percentageMin, 20);
    }

    // Constrain the chargeState between 0 and 100
    chargeState = constrain(chargeState, 0, 100);

    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    //Mavlink needs voltage in mA//Mavlink needs voltage in mA!!! Static Cast -> Typeumwandlung gewzungen
    uint16_t voltages[10] = {static_cast<uint16_t>(voltage1 * 1000), static_cast<uint16_t>(voltage2 * 1000), static_cast<uint16_t>(voltage3 * 1000), 0, 0, 0, 0, 0, 0, 0}; 
    mavlink_msg_battery_status_pack(1, 200, &msg, 0, 0, Batterytype, INT16_MIN, voltages, -1, -1, -1, -1, -1, chargeState);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    Serial2.write(buf, len); //send over serial 2!
}
