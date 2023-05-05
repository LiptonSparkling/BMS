#ifndef CURRENT_H
#define CURRENT_H
#include <ADC.h>
#include "battery_monitor.h"
#include <Arduino.h>

//Resistors for voltage-devider
const int R7 = 10000;
const int R8 = 19000;

const int Current_PIN = 6;
// ADC Pin for currentsensor
//const int Current_PIN = 6;


class Current {
  public:
  void currentmess();
    Current() {
      pinMode(Current_PIN, INPUT);
      adc->adc0->setAveraging(4); // set the number of averages
      adc->adc0->setResolution(12); // set the resolution, 12-bit is the default value
      adc->adc0->setConversionSpeed(ADC_CONVERSION_SPEED::MED_SPEED); // change the conversion speed
      adc->adc0->setSamplingSpeed(ADC_SAMPLING_SPEED::MED_SPEED); // change the sampling speed
    }
   private:
    float calculateCurrent(int voltage);
    ADC *adc = new ADC(); // create an ADC object
};

#endif