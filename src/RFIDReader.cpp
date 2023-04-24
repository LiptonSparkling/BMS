#include "RFIDReader.h"

RFIDReader::RFIDReader(byte ssPin, byte rstPin) : _mfrc522(ssPin, rstPin) {}

void RFIDReader::begin() {
  SPI.begin();
  _mfrc522.PCD_Init();
}

bool RFIDReader::readCard() {
  if (!_mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }

  if (!_mfrc522.PICC_ReadCardSerial()) {
    return false;
  }

  // Authenticate using key A
  byte sector = 1;
  byte key[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  MFRC522::MIFARE_Key authKey;
  for (byte i = 0; i < 6; i++) {
    authKey.keyByte[i] = key[i];
  }
  MFRC522::StatusCode status = _mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, sector * 4, &authKey, &(_mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {
    Serial.println("Authentication failed");
    return false;
  }

  // Read data from the block
  byte blockAddr = 4;
  byte bufferSize = sizeof(_buffer);
  status = _mfrc522.MIFARE_Read(blockAddr, _buffer, &bufferSize);

  if (status != MFRC522::STATUS_OK) {
    Serial.println("Reading failed");
    return false;
  }

  _mfrc522.PICC_HaltA(); // Halt PICC
  _mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD

  return true;
}


byte RFIDReader::getSerialNumber() {
  return _buffer[0];
}

int RFIDReader::getCapacity() {
  return (_buffer[1] << 8) | _buffer[2];
}

byte RFIDReader::getNumCells() {
  return _buffer[3];
}

float RFIDReader::getCellVoltage() {
  return _buffer[4] + (float)_buffer[5] / 100;
}

byte RFIDReader::getMaxCapacityPercent() {
  return _buffer[6];
}

