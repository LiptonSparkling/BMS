#ifndef LOGGING_H
#define LOGGING_H
#include "battery_monitor.h"


//LED on Teensy for logging
const int ledPin = 13;

class Logging {
  public:

    void loggingsetup();
    void logging();

  private:

};

#endif