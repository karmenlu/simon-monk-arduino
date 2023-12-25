/*
 * Advanced I/O: Tones
 * Tone function allows you to generate a square-wave
 * signal on one of the digital output pins.
 * 
 * Built-ins:
 * void tone(int pinNumForTone, int freqInHz, (optional) duration); 
 * void noTone(int pinNumForTone);
 * 
 * If no duration is provided, tone will play indefinitely.
 */
void setup() {
  tone(4, 500);
}

void loop() {
}
