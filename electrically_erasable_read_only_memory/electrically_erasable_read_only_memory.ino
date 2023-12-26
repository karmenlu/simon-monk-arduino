/*
 * EEPROM
 * 
 * The ATMega328 at the heart of the Arduin Uno has a kilobyte 
 * of electrically erasable read-only memory (EEPROM).
 * Despite its name, you can write to EEPROM.
 * 
 * Read and write, one byte at a time.
 * 
 * This program allows you to enter a single-digit
 * letter code from the Serial Monitor.
 * Then remembers the digit and repeatedly writes it out
 * to the Serial Monitor.
 * 
 * EEPROM takes two args:
 * 1) address which is the memory location in EEPROM and should be between 0, 1023
 * 2) data to write at that location, a single byte. Cannot directly store a 16-bit int.
 */
#include <EEPROM.h>

int addr = 0;
char ch;

void setup() {
  Serial.begin(9600);
  ch = EEPROM.read(addr);

}

void loop() {
  if (Serial.available() > 0)
  {
    ch = Serial.read();
    EEPROM.write(0, ch);
    Serial.println(ch);
  }
  Serial.println(ch);
  delay(1000);
}
