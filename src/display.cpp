#include "display.h"
#include "battery_monitor.h"

Display myDisplay;

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);


void Display::init() {
  // Initialize display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //0x3C = Adress
  display.clearDisplay(); // clear buffer
  display.display();
  display.setRotation(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Initialized");

  delay(5000);
}



//Noch nicht funktionsfähig -> Stürzt ab sobald man es aufruft!
void Display::Output() {

// Read cell voltages
float cell1Voltage = getCellVoltage(cell1Pin, cell1Divider, cell1Calibration);
float cell2Voltage = getCellVoltage(cell2Pin, cell2Divider, cell2Calibration) - cell1Voltage;
float cell3Voltage = getCellVoltage(cell3Pin, cell3Divider, cell3Calibration) - cell1Voltage - cell2Voltage;

// Display cell voltages
display.setCursor(0, 0);
display.println("Cell 1 : " + String(cell1Voltage, 3) + " V");
display.println("Cell 2 : " + String(cell2Voltage, 3) + " V");
display.println("Cell 3 : " + String(cell3Voltage, 3) + " V");
display.println("Current : " + String(0, 3) + " A");

// Display the screen
display.display();
 // Regelmäßige Aktualisierung des Displays
while (true) {
display.display();
delay(100);
  }
}


void Display::clear() {
  display.clearDisplay();
  display.display();
}