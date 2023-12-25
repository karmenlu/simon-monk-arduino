const int outPin = 3;

void setup() {
  pinMode(outPin, OUTPUT); // Mode can be INPUT, INPUT_PULLUP, or OUTPUT
  Serial.begin(9600);
  Serial.println("Enter 0 or 1");
}

void loop() {
  if (Serial.available() > 0) // Something placed into buffer by UART?
  {
    char ch = Serial.read();
    if (ch == '1')
    {
      digitalWrite(outPin, HIGH);
    } else if (ch == '0')
    {
      digitalWrite(outPin, LOW); 
    }
  }

}
