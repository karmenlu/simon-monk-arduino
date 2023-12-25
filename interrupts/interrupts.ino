/*
 * Blinks an LED but changes the blink period
 * when an interrupt is received. 
 * 
 * Simulate an interrupt by connecting your wire
 * between pin D2 and GND, using the internal pull-up resistor
 * to keep the interrupt high most of the time.
 */
const int interruptPin = 2;
const int ledPin = 13;
int period = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  // First argument specifies which of two interrupts: D2 or D3.
  // 0 means D2
  // 1 means D3
  // Second argument is function to be called on interrupt.
  // Last argument is one of: CHANGE, RISING, FALLING
  attachInterrupt(0, goFast, FALLING);

  // Disable interrupts with `noInterrupts()`
  // Resume with `interrupts()`
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(period);
  digitalWrite(ledPin, LOW);
  delay(period);
}

void goFast()
{
  period = 100;
}
