#include "current.h"

CURRENT::CURRENT(int pin, float sensitivity, float calibration_factor, float offset, int measurements) {
  adc = new ADC();
  this->pin = pin;
  this->sensitivity = sensitivity;
  this->calibration_factor = calibration_factor;
  this->offset = offset;
  this->measurements = measurements;
}

void CURRENT::setup() {
  adc->adc0->setResolution(12);
}

float CURRENT::read() {
    float sum = 0.0;
    for (int i = 0; i < measurements; i++) {
    int sensor_value = adc->analogRead(pin);
    float voltage = ((sensor_value / 4095.0f) * 3.3f - offset);
    float current = (voltage / sensitivity * calibration_factor);

    sum += current;
    delay(5);
  }
   float average_current = (sum / measurements)*0.77; //Spannungsteiler 1/3
   return average_current;
 }