#include <Arduino.h>

int LED_PIN = 13;
int TASTER_PIN = 12;

int tasterZustand;

void setup() {
  pinMode(LED_PIN, OUTPUT);           // LED_PIN als Ausgang
  pinMode(TASTER_PIN, INPUT_PULLUP);  // Eingang mit aktiviertem internen Pull-Up Widerstand
  
  Serial.begin(9600);                 // Seriellen Monitor starten
}

void loop() {
  tasterZustand = digitalRead(TASTER_PIN); // Zustand vom Taster einlesen

  if (tasterZustand == LOW) {       // Wenn Taster gedrückt
    digitalWrite(LED_PIN, HIGH);    // LED einschalten
  } else {                          // Wenn Taster NICHT gedrückt
    digitalWrite(LED_PIN, LOW);     // LED ausschalten
  }
}