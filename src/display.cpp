#include "display.h"
#include "battery_monitor.h"

#define OLED_RESET -1

Display myDisplay;
Adafruit_SSD1306 display(OLED_RESET);

//Display init function
void Display::init() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setRotation(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("BMS Starup");
  display.display();
  delay(1000);
  display.clearDisplay();
}

void Display::Output(const BatteryState& state) {

  display.clearDisplay();
  display.setCursor(0,0);
  //Plot total Voltage
  display.print("Tot.Voltage: ");
  display.print(state.totalVoltage);
  display.println(" V");
  //Plot current
  display.print("Current: ");
  display.print(state.current);
  display.println(" A");
  //Plot Temperature 1
  display.print("Temp 1: ");
  display.print(state.temperatures[0]);
  display.println(" C");
  //Plot Temperature 2
  display.print("Temp 2: ");
  display.print(state.temperatures[1]);
  display.println(" C");

  display.display();

}

void Display::clear() {
  display.clearDisplay();
  display.display();
}