/*
 * Analog Outputs
 * Pins 3, 5, 6, 9, 10, 11 have ~
 * can provide variable output other than just 5V/0V.
 * 
 * With PWM, brightness can be controlled by varying
 * the average amount of time that the LED is on.
 * Giving us a linear control of the brightness.
*/
const int outputPin = 3;

void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Volts 0 to 5");
}

void loop() {
  if (Serial.available() > 0)
  {
    float volts = Serial.parseFloat();
    
    // Convert voltage (0 to 5) to PWM output (0 to 255)
    int pwmValue = volts * 255.0 / 5.0;
    
    analogWrite(outputPin, pwmValue);
  }
}
