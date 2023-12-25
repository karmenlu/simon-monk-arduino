const int LEDPIN = 13;
const int PAUSE_MS = 3000;
const int delayPeriod = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  flash(LEDPIN, 20, delayPeriod);
  delay(PAUSE_MS);
}

void flash(int ledPin, int numFlashes, int delayMs) {
  for (int i=0; i<numFlashes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(delayMs);
    digitalWrite(ledPin, LOW);
    delay(delayMs);
  }
}
