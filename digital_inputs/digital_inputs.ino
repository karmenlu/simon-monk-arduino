const int inputPin = 5;

void setup() {
  // To enable software-configurable pull-up resistor
  // set pinMode to INPUT_PULLUP rather than INPUT.
  pinMode(inputPin, INPUT_PULLUP);  
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(inputPin);
  Serial.println(reading);
  delay(1000);
}
