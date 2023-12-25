/*
Demo: bouncing doesn't always matter.
Lights an LED while the button is pressed
*/
const int inputPin = 5;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
}

void loop() {
  // switchOpen is 0 when button is pressed.
  // is 1 when it not pressed. 
  // Pulled up to 1 when the button is not pressed.
  int switchOpen = digitalRead(inputPin);
  digitalWrite(ledPin, ! switchOpen);

}
