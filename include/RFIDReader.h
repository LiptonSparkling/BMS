#ifndef RFIDReader_h
#define RFIDReader_h

#include <Arduino.h>
#include "SPI.h"
#include "MFRC522.h"


class RFIDReader {
public:
  RFIDReader(byte ssPin, byte rstPin);
  void begin();
  bool readCard();
  byte getSerialNumber();
  int getCapacity();
  byte getNumCells();
  float getCellVoltage();
  byte getMaxCapacityPercent();

private:
  MFRC522 _mfrc522;
  byte _buffer[18];
  byte _bufferSize;
};

#endif