/*
 * Range Compression 
 * 
 * If you care about range of 0 to 60 degrees
 * Celsius, then multiply every temperature
 * by 4 before converting to a byte and saving it.
 * 
 * When reading back, you can divide by 4 to get
 * a value that has a precision of 0.25 of a degree.
 */
#include <EEPROM.h>

void setup() {
  float tempFloat = 20.75;
  byte tempByte = (int)(tempFloat * 4);
  EEPROM.write(0, tempByte);

  byte tempByte2 = EEPROM.read(0);
  float temp2 = (float) (tempByte2) / 4;
  Serial.begin(9600);
  Serial.println("\n\n\n");
  Serial.println(temp2);
}

void loop() {
}
