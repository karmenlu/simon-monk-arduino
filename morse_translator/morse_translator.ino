/* Morse Code Translator
*/

char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".",  // A-I
  "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", // J-R
  "---", ".--.", "--.-", ".-.", 
  "...", "-", "..-", "...-", ".--",  // S-Z
  "-..-", "-.--", "--.."
};

char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----."
};

const int dotDelay = 200;
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char ch;
  if (Serial.available() > 0)
  {
    ch = Serial.read();
    if (ch >= 'a' && ch <= 'z') // ACII codes: a == 97, z == 122
    {
      flashSequence(letters[ch - 'a']);
    } else if (ch >= 'A' && ch <= 'Z')
    {
      flashSequence(letters[ch - 'A']);
    } else if (ch >= '0' && ch <= '9')
    {
      flashSequence(numbers[ch - '0']);
    } else if (ch == ' ' )
    {
      delay(dotDelay * 4); // gap between words
    }
  }
}

void flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] != '\0')
  {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3); // gap between letters
}

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(LED_PIN, HIGH);
  if (dotOrDash == '.')
  {
    delay(dotDelay);
  } else {
    delay(dotDelay * 3);
  }
  digitalWrite(LED_PIN, LOW);
  delay(dotDelay); // gap between flashes
}
