#ifndef MAVLINK_MESSAGES_H
#define MAVLINK_MESSAGES_H

#include "common/mavlink.h"
#include "common/mavlink_msg_battery_status.h"
#include <Arduino.h>
#include "battery_monitor.h"
#include "temperature.h"
#include "current.h"

// Define pins for Mavlink
#define RST_PIN 9
#define SS_PIN  10

// Define Batterytype -> Choose
extern int Batterytype;


class MavlinkMessages {
public:
    void send_battery_status(const BatteryState& state);

private:

};

#endif
