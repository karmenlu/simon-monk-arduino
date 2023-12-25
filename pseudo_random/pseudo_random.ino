/**
 * The Arduino language is based on an earlier library (Wiring)
 * and complements another library (Processing).
 * 
 * Processing is based on Java language, rather than C and
 * is used to link Arduino over USB.
 * 
 * Arduino IDE is based on Processing.
 * 
 * int random(n) -> random # between 0 and n - 1 
 * int random(n, m) -> # between n and m - 1
 * 
 * Numbers will be pseudo-random because they have a random distribution.
 */
void setup() {
  Serial.begin(9600);
}

void loop() {
  int number = random(1, 7);
  Serial.println(number);
  delay(500);
}
