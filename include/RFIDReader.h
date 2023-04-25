#ifndef RFIDReader_h
#define RFIDReader_h

#include <Arduino.h>
#include "SPI.h"
#include "MFRC522.h"


class RFIDReader {
public:
  RFIDReader(byte ssPin, byte rstPin);
  void begin();
  bool readCard(); //function to read the RFID Tag
  byte getSerialNumber(); //get the serialnumber of the battery
  int getCapacity(); //get the nominal capacity of the batter
  byte getNumCells(); //get the number of cells from the battery
  float getCellVoltage(); //get the voltage per cell from the battery
  byte getMaxCapacityPercent(); //get the max. usable capacity from the battery

private:
  MFRC522 _mfrc522;
  byte _buffer[18];
  byte _bufferSize;
};

#endif