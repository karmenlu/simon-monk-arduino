int LEDPIN = 13;
int delayPeriod = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDPIN, HIGH);
  delay(delayPeriod);
  digitalWrite(LEDPIN, LOW);
  delay(delayPeriod);
  delayPeriod = delayPeriod + 100;
  if (delayPeriod > 3000)
  {
    delayPeriod = 100;  
  }
}
