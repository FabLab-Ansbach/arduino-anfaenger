#include <Arduino.h>

int LED_PIN = 12;
int TASTER1_PIN = 8;
int TASTER2_PIN = 9;
int TASTER3_PIN = 10;
int TASTER4_PIN = 11;

bool taster1Zustand = LOW;
bool taster2Zustand = LOW;
bool taster3Zustand = LOW;
bool taster4Zustand = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);           // LED_PIN als Ausgang
  pinMode(TASTER1_PIN, INPUT_PULLUP);  // Eingang mit aktiviertem internen Pull-Up Widerstand
  pinMode(TASTER2_PIN, INPUT_PULLUP);
  pinMode(TASTER3_PIN, INPUT_PULLUP);
  pinMode(TASTER4_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, HIGH);        // Am Anfang LED anschalten
  
  Serial.begin(9600);                 // Seriellen Monitor starten
}

void loop() {
  taster1Zustand = digitalRead(TASTER1_PIN);
  taster2Zustand = digitalRead(TASTER2_PIN);
  taster3Zustand = digitalRead(TASTER3_PIN);
  taster4Zustand = digitalRead(TASTER4_PIN);
  
  if ((taster1Zustand == LOW) && (taster2Zustand == LOW)) {
    digitalWrite(LED_PIN, HIGH);
  } else if ((taster3Zustand == LOW) || (taster4Zustand == LOW)) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

}