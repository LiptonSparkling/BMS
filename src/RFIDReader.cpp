#include "RFIDReader.h"

RFIDReader::RFIDReader() : mfrc522(SS_PIN, RST_PIN) {}

void RFIDReader::initialize() {
    SPI.begin();
    mfrc522.PCD_Init();
    delay(1000);
    Serial.println("BMS RFID reading module initialized.");
}

// Modify the readCard method
RFIDReader::RFIDData RFIDReader::readCard() {
 
  RFIDReader::RFIDData data;

  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return data; // return empty data if no new card is present or if reading the card serial fails
  }

  Serial.print("UID tag :");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Start reading: ");

  byte sector = 1;
  byte key[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  MFRC522::MIFARE_Key authKey;
  for (byte i = 0; i < 6; i++) {
    authKey.keyByte[i] = key[i];
  }
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, sector * 4, &authKey, &(mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {
    Serial.println("Authentication failed");
    return data;
  }

  // Read data from the block
  byte blockAddr = 4;
  byte buffer[18];
  byte bufferSize = sizeof(buffer);
  status = mfrc522.MIFARE_Read(blockAddr, buffer, &bufferSize);

  if (status != MFRC522::STATUS_OK) {
    Serial.println("Reading failed");
    return data;
  }

  data.serialNumber = buffer[0];
  data.capacity = (buffer[1] << 8) | buffer[2];
  data.numCells = buffer[3];

  float cellVoltage = buffer[4] + (float)buffer[5] / 100;
  byte maxCapacityPercent = buffer[6];

  Serial.print("Serial Number: ");
  Serial.println(data.serialNumber);
  Serial.print("Capacity: ");
  Serial.println(data.capacity);
  Serial.print("Number of Cells: ");
  Serial.println(data.numCells);
  Serial.print("Cell Voltage: ");
  Serial.println(cellVoltage, 2);
  Serial.print("Max Capacity Percent: ");
  Serial.println(maxCapacityPercent);
  Serial.println("Read data for BMS RFID-TAG complete!");


  // Halt PICC
  mfrc522.PICC_HaltA();
  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();

  return data;
}