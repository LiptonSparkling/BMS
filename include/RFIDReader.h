#ifndef RFID_READER_HPP
#define RFID_READER_HPP

#include <SPI.h>
#include <MFRC522.h>

class RFIDReader {
public:
    static constexpr uint8_t RST_PIN = 9;
    static constexpr uint8_t SS_PIN = 10;
    struct RFIDData {
        byte serialNumber;
        int capacity;
        byte numCells;
        float cellVoltage;
        byte maxCapacityPercent;
    };

    RFIDReader();
    void initialize();
    RFIDData readCard();

private:
    MFRC522 mfrc522;
};

#endif
