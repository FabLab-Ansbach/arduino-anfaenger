#include <Arduino.h>

int LED_ROT = 13;
int LED_GELB = 12;
int LED_GRUEN = 11;

int LED_FUSS_ROT = 10;
int LED_FUSS_GRUEN = 9;

int TASTER = 8;

int tasterZustand;
bool fussgaenger = false;

void setup() {
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_GELB, OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);
  pinMode(LED_FUSS_ROT, OUTPUT);
  pinMode(LED_FUSS_GRUEN, OUTPUT);
  pinMode(TASTER, INPUT_PULLUP);

  // Am Anfang sind alle Ampeln Rot
  digitalWrite(LED_ROT, HIGH);
  digitalWrite(LED_GELB, LOW);
  digitalWrite(LED_GRUEN, LOW);
  digitalWrite(LED_FUSS_ROT, HIGH);
  digitalWrite(LED_FUSS_GRUEN, LOW);

  Serial.begin(9600);                 // Seriellen Monitor starten
}

void loop() {

  tasterZustand = digitalRead(TASTER);  // Zustand von Taster einlesen
  if (tasterZustand == LOW) {           // Taster wurde gedrückt
    fussgaenger = true;
  }

  // Stop => Rot
  digitalWrite(LED_ROT, HIGH);
  digitalWrite(LED_GELB, LOW);
  digitalWrite(LED_GRUEN, LOW);
  delay(3000);

  if (fussgaenger) {                    // Fußgänger hat gedrückt
    digitalWrite(LED_FUSS_ROT, HIGH);
    delay(500);
    digitalWrite(LED_FUSS_ROT, LOW);
    digitalWrite(LED_FUSS_GRUEN, HIGH);
    delay(3000);
    digitalWrite(LED_FUSS_ROT, HIGH);
    digitalWrite(LED_FUSS_GRUEN, LOW);
    delay(500);
    fussgaenger = false;                // Fußgängerampel hat fertig geschaltet
  }
  
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
  digitalWrite(LED_GRUEN, LOW);
  delay(1000);
}