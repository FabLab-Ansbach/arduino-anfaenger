#include <Arduino.h>

// Variablen anlegen
int LED_1 = 13;
int LED_2 = 13;

int ZEIT_1 = 1000;
int ZEIT_2 = 300;
int ZEIT_3 = 1400;
int ZEIT_4 = 500;

// Wird beim Programmstart genau 1x ausgeführt
void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

// Wird immer wieder ausgeführt
void loop() {
  digitalWrite(LED_1, HIGH);
  delay(ZEIT_1);
  digitalWrite(LED_2, HIGH);
  delay(ZEIT_2);
  digitalWrite(LED_2, LOW);
  delay(ZEIT_3);
  digitalWrite(LED_1, LOW);
  delay(ZEIT_4);
}