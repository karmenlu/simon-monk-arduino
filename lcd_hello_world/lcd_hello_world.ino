/*
 * This is a program that will take in 
 * a message over serial and dislay it on
 * an LCD Display. 
 * 
 * I2C LCD Display to Arduino UNO R3
 * 
 * Wiring:
 * Four pins on the back of the display:
 * GND pin, connects to UNO's GND
 * VCC, the power pin, connect to 5V
 * SDA, i2c "I squared C" data, connects to UNO's pin A4
 * SCL, "I squared C clock", connects to UNO's A5
 * 
 * Run the i2c Scanner sketch to get the i2c Device.
 * (I found mine at address 0x27)
 * 
 * Note: I used a screwdriver to turn the 
 * Contrast Adjust. Trimpot.
 * 
 * Site with labelled images:
 * https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/
 */
// The wire library is used by Liquid Crystal Library to provide i2c communication
// with the backpack on the display
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int PAUSE_MS = 3000;
const int MAX_BUF_SIZE = 20;
char buffer[MAX_BUF_SIZE];

/* First arg: 0x27 is the i2c address identified by the i2c scanner.
 * Other args are pin assignments for the PCF8574T 8-bit I/O Expander Chip
 * on the i2c backpack. (Different backpacks have different configurations.)
 */
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16,2); // Initializes interface, specifying width and height
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter a message to print on liquid crystal:");
  while(!Serial.available()) {};
  int n = Serial.readBytesUntil('\n', buffer, MAX_BUF_SIZE);
  buffer[n] = '\0';
  printMessage(buffer);
  delay(PAUSE_MS);
}

void printMessage(char message[]) {
  lcd.clear();     // Clears display, puts cursor in upper-left corner
  lcd.backlight();
  lcd.print(message);  
}
