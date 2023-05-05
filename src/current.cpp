#include "current.h"

// Object current
Current current;

// Offset voltage when no current is flowing
// 0 Current -> Offset 0.96A
const float OFFSET_VOLTAGE = 0.32;
const float sensity = 0.04; // Sensitivity for ACS758LCB-050B-PFF-T sensor is 40 mV/A

void Current::currentmess() {

  // Read the raw analog voltage value from the current sensing pin
  int rawValue = adc->adc0->analogRead(Current_PIN);

  // Calculate voltage on Analogpin A6
  float VAout = rawValue * (3.3 / 4095.0);

  // Calculate the input voltage (Vin) at the ACS758 output
  float Vin = VAout * (static_cast<float>(R7 + R8) / static_cast<float>(R7));

  // Calculate voltage drop across sensor by subtracting offset voltage
  float Vdrop = Vin - OFFSET_VOLTAGE;

  // Calculate current using sensitivity value
  float current = Vdrop / (sensity * 1000.0);

/*
  // Output corrected current in amperes
  Serial.print("Volt Analogpin A6 = ");
  Serial.print(VAout);
  Serial.println(" V");

  Serial.print("Input voltage (Vin) at ACS758 output = ");
  Serial.print(Vin);
  Serial.println(" V");

  Serial.print("Voltage drop across sensor - Offset = ");
  Serial.print(Vdrop);
  Serial.println(" V");

  Serial.print("Calculated current including sensity = ");
  Serial.print(current);
  Serial.println(" A");
  Serial.println("-----------------------");
  delay(1000);
  */
}



