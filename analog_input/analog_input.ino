/* Analog Inputs provide a value between 0 and 1023
 *  depending on voltage at the analog input pin.
 *  
 *  This sketch displays the reading and actual voltage 
 *  at the analog pin A0 at every 0.5 second.
 */
const int analogPin = 0;
const float maximumAnalogReading = 1023.0;
const float maximumVoltage = 5.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(analogPin);
  float voltage = reading / (maximumAnalogReading / maximumVoltage); // quotient == 204.6
  Serial.print("Reading=");
  Serial.print(reading);
  Serial.print("\t\tVolts=");
  Serial.println(voltage);
  delay(500);
}
