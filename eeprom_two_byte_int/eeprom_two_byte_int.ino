// Write and read a 2-byte int
// (Use the AVR EEPROM library for larger data types.)
#include <EEPROM.h>

void setup() {
  int x = 1234; // 0b0000010011010010

  // Write an int as two bytes
  EEPROM.write(0, highByte(x)); // 0000 0100
  EEPROM.write(1, lowByte(x));  // 1101 0010

  // Read the int back
  byte high = EEPROM.read(0);
  byte low = EEPROM.read(1);
  // Move the 8 high bytes to the top of the int and then add the low byte
  int y = (high << 8) + low;
}

void loop() {
}
