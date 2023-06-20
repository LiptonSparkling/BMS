#ifndef RFIDReader_h
#define RFIDReader_h

#include <SPI.h>
#include <MFRC522.h>

class RFIDReader {
private:
  MFRC522 mfrc522;
  byte serialNumber;
  int capacity;
  byte numCells;
  float cellVoltage;
  byte maxCapacityPercent;

public:
  RFIDReader(byte rstPin, byte ssPin);

  void setup();
  void readData();
  void printData();
};

#endif
