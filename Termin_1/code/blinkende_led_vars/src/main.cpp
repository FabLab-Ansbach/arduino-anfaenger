#include <Arduino.h>

// Variablen anlegen
int LED_PIN = 13;
int ZEIT_AUS = 1000;
int ZEIT_EIN = 1000;

// Wird beim Programmstart genau 1x ausgeführt
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

// Wird immer wieder ausgeführt
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_EIN);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
}