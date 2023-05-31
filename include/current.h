#ifndef CURRENT_H
#define CURRENT_H

#include <ADC.h>

const int AMPERE_PIN = 41; //Datapin 
const float DEFAULT_SENSITIVITY = 0.04;  //Datasheet
const float DEFAULT_CALIBRATION_FACTOR = 0.95; //0.916; //Gemessen bei 1A 
const float DEFAULT_OFFSET = 0.34396;//0.352; //Offsetspannung bei 0A 
const int DEFAULT_MEASUREMENTS = 20; //Summe der Messungen für Mittelwert


class CURRENT {
  private:
    ADC *adc;
    int pin;
    float sensitivity;
    float calibration_factor;
    float offset;
    int measurements;
  public:
    CURRENT(int pin = AMPERE_PIN, float sensitivity = DEFAULT_SENSITIVITY, float calibration_factor = DEFAULT_CALIBRATION_FACTOR, float offset = DEFAULT_OFFSET, int measurements = DEFAULT_MEASUREMENTS);
    void setup();
    float read();
};

#endif
