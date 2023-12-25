const int LEDPIN = 13;
int PAUSE_MS = 3000;
int delayPeriod = 100;

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  for(int i=0; i<20; i++)
  {
    digitalWrite(LEDPIN, HIGH);
    delay(delayPeriod);
    digitalWrite(LEDPIN, LOW);
    delay(delayPeriod);
  }
  delay(PAUSE_MS);
}
