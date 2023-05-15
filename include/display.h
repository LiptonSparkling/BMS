#ifndef DISPLAY_H
#define DISPLAY_H

#include "battery_monitor.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


class Display {
  public:
    void init();
    void clear();
   // void Output(float cell1Voltage, float cell2Voltage, float cell3Voltage, float totalVoltage, float ampere, float temperature_1);
   void Output(float totalVoltage,  float current, float temperature_1);

    

  private:
    Adafruit_SSD1306 display;
};

#endif