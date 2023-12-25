// Debounce with Bounce library.
#include <Bounce2.h>
const int inputPin = 5;
const int ledPin = 13;

int ledValue = LOW;
Bounce bouncer = Bounce();

void setup() {
  pinMode(inputPin, INPUT_PULLUP); // When not pressed, pulls reading up to 1.
  pinMode(ledPin, OUTPUT);
  bouncer.attach(inputPin);
}

void loop() {
  if(bouncer.update() && bouncer.read() == LOW)
  {
    ledValue = ! ledValue;
    digitalWrite(ledPin, ledValue);
  }
}
