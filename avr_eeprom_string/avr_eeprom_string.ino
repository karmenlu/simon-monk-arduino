/*
 * Reads and writes passwords from EEPROM.  
 * Displays a password read from EEPROM,
 * prompts for a new password, 
 * poweroff and plug in, old password still there.
 */
#include <avr/eeprom.h>
const int maxPasswordSize = 20;
char password[maxPasswordSize];

void setup() {
  // Read EEPROM contents
  eeprom_read_block(&password, 0, maxPasswordSize);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Your password is:");
  Serial.println(password);
  Serial.println("Enter a new password!");
  
  while(!Serial.available()) {}; // Do nothing until communication arrives at serial
  
  int n = Serial.readBytesUntil('\n', password, maxPasswordSize);
  password[n] = '\0';
  eeprom_write_block(password, 0, maxPasswordSize);
  Serial.print("Saved Password: ");
  Serial.println(password);
}
