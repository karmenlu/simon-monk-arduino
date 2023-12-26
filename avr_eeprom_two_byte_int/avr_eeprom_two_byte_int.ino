/*
 * The AVR EEPROM Library
 * 
 * `eeprom_write_block` args:
 * 1) reference to the variable's address in memory
 * 2) starting byte in EEPROM where the block should be written
 * 3) number of bytes to write (2 for an int).
 */
#include <avr/eeprom.h>

void setup() {
  Serial.begin(9600);
  int i1 = 123;
  eeprom_write_block(&i1, 0, 2);
  int i2 = 0;
  eeprom_read_block(&i2, 0, 2);
  Serial.println(i2);
}

void loop() {
}
