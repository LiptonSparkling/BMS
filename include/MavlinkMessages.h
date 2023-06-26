#ifndef MAVLINK_MESSAGES_H
#define MAVLINK_MESSAGES_H

#include <Arduino.h>
#include "battery_monitor.h"

// Define pins for Mavlink
#define RST_PIN 9
#define SS_PIN  10

// Define Batterytype -> Choose
extern int Batterytype;


namespace MavlinkMessages {
    void send_battery_status(const BatteryState& state);
    void send_status_text(uint8_t severity, const char* text);
};

#endif
