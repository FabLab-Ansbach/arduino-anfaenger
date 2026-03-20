#include <Arduino.h>

int LED_ROT = 13;
int LED_GELB = 12;
int LED_GRUEN = 11;

void setup() {
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_GELB, OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);

  // Am Anfang ist die Ampel Rot
  digitalWrite(LED_ROT, HIGH);
  digitalWrite(LED_GELB, LOW);
  digitalWrite(LED_GRUEN, LOW);

  Serial.begin(9600);                 // Seriellen Monitor starten
}

void loop() {
  // Stop => Rot
  digitalWrite(LED_ROT, HIGH);
  digitalWrite(LED_GELB, LOW);
  digitalWrite(LED_GRUEN, LOW);
  delay(3000);
  
  // Achtung => Rot + Gelb
  digitalWrite(LED_GELB, HIGH);
  delay(1000);

  // Fahrt => Grün
  digitalWrite(LED_ROT, LOW);
  digitalWrite(LED_GELB, LOW);
  digitalWrite(LED_GRUEN, HIGH);
  delay(3000);

  // Bremsen => Gelb
  digitalWrite(LED_GELB, HIGH);
  delay(1000);
}