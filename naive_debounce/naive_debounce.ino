// Toggles LED with naive debounce
// Naive debounce: add a delay to let bouncing subside.
// (-): Holding button down, LED keeps flashing
// (-): Delay means program unable to detect press of any other button.
const int inputPin = 5;
const int ledPin = 13;
int ledValue = LOW;

void setup() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(digitalRead(inputPin) == LOW)
  {
    ledValue = ! ledValue;
    digitalWrite(ledPin, ledValue);
    delay(500); 
  }
}
