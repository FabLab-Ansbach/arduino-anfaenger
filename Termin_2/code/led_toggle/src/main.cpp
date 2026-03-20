#include <Arduino.h>

int LED_PIN = 13;
int TASTER_PIN = 12;

int tasterZustand;
int ledZustand = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);           // LED_PIN als Ausgang
  pinMode(TASTER_PIN, INPUT_PULLUP);  // Eingang mit aktiviertem internen Pull-Up Widerstand

  digitalWrite(LED_PIN, HIGH);        // Am Anfang LED anschalten
  
  Serial.begin(9600);                 // Seriellen Monitor starten
}

void loop() {
  tasterZustand = digitalRead(TASTER_PIN); // Zustand vom Taster einlesen

  if (tasterZustand == LOW) {         // Taster gedrückt
    ledZustand = !ledZustand;
    digitalWrite(LED_PIN, ledZustand);
  }
  
}