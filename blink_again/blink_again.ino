int LED_PIN = 13;
int delayPeriod = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  delay(delayPeriod);
  digitalWrite(LED_PIN, LOW);
  delay(delayPeriod);
  delayPeriod = delayPeriod + 100;
}
