const int delayDuration = 1000;

// The following is equivalent to:
// const char message[] = "Hello";
// `*` indicates a pointer.
// `message` points to the first char
// element of the char array.
const char *message = "Hello";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(message);
  delay(delayDuration);
}
