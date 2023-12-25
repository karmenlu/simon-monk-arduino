/*
 * Flashes "SOS" in Morse code using the Arduino board's
 * built-in LED.
 * 
 * "S": 3 short flashes (dots)
 * "O" 3 long flashes (dashes)
 * 
 * Durations are in milliseconds (ms).
 */
const int LED_PIN = 13;
const int DOT_DUR = 200;
const int DASH_DUR = 500;
const int PAUSE_MS = 3000;
int durations[] = {DOT_DUR, DOT_DUR, DOT_DUR, DASH_DUR, DASH_DUR, DASH_DUR, DOT_DUR, DOT_DUR, DOT_DUR};

void setup() {
  Serial.begin(9600); // Set baudrate
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  flashDurs();
  delay(PAUSE_MS);
}

void flash(int ledPin, int delayPeriod) {
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);
}

void flashDurs() {
  /*
   * There is no built-in for length of an array.
   * Divide total size of array by size of an array element.
   */
  for(int i=0; i<sizeof(durations)/sizeof(durations[0]); i++)
  {
    flash(LED_PIN, durations[i]);
    Serial.println(durations[i]);
  } 
}
