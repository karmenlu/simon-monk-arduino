/* Seeding the random # generator
 * gives it a starting point for the sequence.
 * 
 * Analog input will float, so use value read rom 
 * analog input to seed the random # generator.
 * 
 * Better random generators may rely on hardware and
 * based on random occurrences like cosmic ray events.
 */
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int number = random(1, 7);
  Serial.println(number);
  delay(500);
}
