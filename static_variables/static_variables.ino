const int LEDPIN = 13;
const int PAUSE_MS = 3000;
const int delayPeriod = 250;

/**
 * The `static` keyword initializes the
 * variable only the first time that 
 * the function is run.
 */
void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  static int count = 0;
  digitalWrite(LEDPIN, HIGH);
  delay(delayPeriod);
  digitalWrite(LEDPIN, LOW);
  delay(delayPeriod);
  count++;
  if (count == 20)
  {
    count=0;
    delay(PAUSE_MS);
  }
}
