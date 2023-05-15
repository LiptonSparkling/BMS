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
  display.println("Initialized BMS");
  display.display();
  delay(1000);
  display.clearDisplay();
}

void Display::Output(float totalVoltage, float current, float temperature_1) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Tot.Voltage:");
  display.print(totalVoltage);
  display.println(" V");
  display.print("Current:");
  display.print(current);
  display.println(" A");
  display.print("Temp:");
  display.print(temperature_1);
  display.print(" C");
  display.display();

}


/*
//Display Output of the values
void Display::Output(float totalVoltage, float current, float temperature_1) {

    display.clearDisplay(); 

    display.setCursor(0, 0);
    display.print("Total Voltage: ");
    display.print(totalVoltage);
    display.println(" V");

    display.setCursor(0, 10);
    display.print("Current: ");
    display.print(current);
    display.println(" A");

    display.setCursor(0, 20);
    display.print("Temperature: ");
    display.print(temperature_1);
    display.println(" °C");
   */
    /*
 //Display Cell 1
    display.setCursor(0, 0);
    display.print("Cell 1: ");
    display.print(cell1Voltage);
    display.println(" V");
  //Display Cell 2
    display.setCursor(0, 10);
    display.print("Cell 2: ");
    display.print(cell2Voltage);
    display.println(" V");
  //Display Cell 3
    display.setCursor(0, 20);
    display.print("Cell 3: ");
    display.print(cell3Voltage);
    display.println(" V");
    display.setCursor(0, 30);
    display.print("Total: ");
    display.print(totalVoltage);
    display.println(" V");
  
    display.display(); 

}
*/

void Display::clear() {
  display.clearDisplay();
  display.display();
}