#include <Arduino.h>

// Wird beim Programmstart genau 1x ausgeführt
void setup() {
  pinMode(13, OUTPUT);
}

// Wird immer wieder ausgeführt
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}