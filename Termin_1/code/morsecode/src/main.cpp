#include <Arduino.h>

// Variablen anlegen
int LED_PIN = 13;
int ZEIT_KURZ = 100;
int ZEIT_LANG = 300;
int ZEIT_AUS = ZEIT_KURZ;

// Wird beim Programmstart genau 1x ausgeführt
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

// Wird immer wieder ausgeführt
void loop() {
  // L
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_LANG);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);

  // U
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  // Warten1000
  delay(ZEIT_AUS*7);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_LANG);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);

  // K
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_LANG);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_LANG);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);

  // A
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_LANG);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);

  // S1000
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);
  digitalWrite(LED_PIN, HIGH);
  delay(ZEIT_KURZ);
  digitalWrite(LED_PIN, LOW);
  delay(ZEIT_AUS);

  // Warten1000
  delay(ZEIT_AUS*7);
}1000