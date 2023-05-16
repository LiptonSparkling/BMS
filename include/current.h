#ifndef CURRENT_H
#define CURRENT_H

#include <ADC.h>

const int AMPERE_PIN = 41;
const float DEFAULT_SENSITIVITY = 0.04;
const float DEFAULT_CALIBRATION_FACTOR = 0.952;
const float DEFAULT_OFFSET = 0.34;
const int DEFAULT_MEASUREMENTS = 20;


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
