#ifndef DISPLAY_H
#define DISPLAY_H

#include "battery_monitor.h"
#include "RFIDReader.h" 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Display {
  public:
    void init();
    void clear();
    void Output(const BatteryState& state);
    void showRFIDData(const RFIDReader::RFIDData& data); 
    
  private:
    Adafruit_SSD1306 display;
};

#endif
