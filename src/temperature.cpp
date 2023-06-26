#include "temperature.h"


//constructor für SPI communication
Temperature::Temperature(uint8_t cs1, uint8_t cs2, uint8_t cs3, uint8_t cs4, uint8_t mosi, uint8_t miso, uint8_t clk, float ref_resistance) :
  _max31865_1(cs1, mosi, miso, clk),
  _max31865_2(cs2, mosi, miso, clk),
  _max31865_3(cs3, mosi, miso, clk),
  _max31865_4(cs4, mosi, miso, clk),
  _ref_resistance(ref_resistance)
{
}

//initialize communication with  MAX31865
void Temperature::begin() {
  _max31865_1.begin(MAX31865_2WIRE); //All are 2 wire connection -> Adjust here if 3/4 wire
  _max31865_2.begin(MAX31865_2WIRE); //All are 2 wire connection -> Adjust here if 3/4 wire
  _max31865_3.begin(MAX31865_2WIRE); //All are 2 wire connection -> Adjust here if 3/4 wire
  _max31865_4.begin(MAX31865_2WIRE); //All are 2 wire connection -> Adjust here if 3/4 wire
}


//calculating temp in method temperature in Adafruit lib
float Temperature::getTemperature(uint8_t sensor_num, float rtd_nominal) {
  switch (sensor_num) {
    case 1:
      return _max31865_1.temperature(rtd_nominal, _ref_resistance);
      break;
    case 2:
      return _max31865_2.temperature(rtd_nominal, _ref_resistance);
      break;
    case 3:
      return _max31865_3.temperature(rtd_nominal, _ref_resistance);
      break;
    case 4:
      return _max31865_4.temperature(rtd_nominal, _ref_resistance);
      break;
    default:
      return -9999.0; //Temprange -200°C to 850°C -9999 can be asily recognized as an error
      break;
  }
}

//Find out maxTemp for MavlinkMessage
float Temperature::getMaxTemperature() {
    float maxTemp = _temperature1;
    if (_temperature2 > maxTemp) {
        maxTemp = _temperature2;
    }
    if (_temperature3 > maxTemp) {
        maxTemp = _temperature3;
    }
    return maxTemp;
}