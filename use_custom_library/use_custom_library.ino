/*  Sketch using a custom Flasher library.
 *  To use, the folder with the library contents should
 *  be located at `~/Arduino/libraries` (Ubuntu)
 *  `MyDocuments\Arduino` (Windows),
 *  `Documents/Arduino/` (Mac)
 */
#include <Flasher.h>

const int ledPin = 13;
const int slowDuration = 300;
const int fastDuration = 100;

Flasher slowFlasher(ledPin, slowDuration);
Flasher fastFlasher(ledPin, fastDuration);

void setup() {}

void loop() {
  slowFlasher.flash(5);
  delay(1000);
  fastFlasher.flash(10);
  delay(2000);
}
