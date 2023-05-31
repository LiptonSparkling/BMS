#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <Adafruit_MAX31865.h>

// Vierten Sensor integrieren

//Defintion of the Pins
#define MAX31865_MOSI 26
#define MAX31865_CLK  27
#define MAX31865_MISO 39

//Defintion of the Chipselect Pins 
#define MAX31865_CS_1   22
#define MAX31865_CS_2   21
#define MAX31865_CS_3   23
#define MAX31865_CS_4   24

//Resistance Temperature Detector
//Calibrate this resistors if temp is not correct
#define RTD_NOMINAL_1   100.164
#define RTD_NOMINAL_2   100.11
#define RTD_NOMINAL_3   100.12 
#define RTD_NOMINAL_4   100.10

//Ref resistance onboard
#define RTD_REF_RESISTANCE 430.0


class Temperature {
  public:
    Temperature(uint8_t cs1, uint8_t cs2, uint8_t cs3, uint8_t cs4, uint8_t mosi, uint8_t miso, uint8_t clk, float ref_resistance);
    void begin();
    float getTemperature(uint8_t sensor_num, float rtd_nominal);
    
  private:
    Adafruit_MAX31865 _max31865_1;
    Adafruit_MAX31865 _max31865_2;
    Adafruit_MAX31865 _max31865_3;
    Adafruit_MAX31865 _max31865_4;
    float _ref_resistance;
};

#endif
