#include <Arduino.h>

int TASTER_PIN = 12;
int LED1_PIN = 11;
int LED2_PIN = 10;
int LED3_PIN = 9;
int LED4_PIN = 8;
int LED5_PIN = 7;

bool tasterZustand = LOW;
bool tasterZustandAlt = LOW;

int laufindex = 1;
// Modus
// 0 => Eine LED geht der Reihe nach ein und wieder aus
// 1 => Es kommt immer eine LED dazu
int modus = 0;

void setup() {
  pinMode(TASTER_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);

  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  digitalWrite(LED5_PIN, LOW);
  
  Serial.begin(9600);                 // Seriellen Monitor starten
}

void loop() {
  tasterZustand = digitalRead(TASTER_PIN);

  // Tasterauswertung
  if (tasterZustand != tasterZustandAlt) {
    if (tasterZustand == LOW) {       // Taster wurde gedrückt
      laufindex = laufindex + 1;
      if (laufindex > 5) {
        laufindex = 1;
      }
    }
    delay(100);
  }

  tasterZustandAlt = tasterZustand;

  // LED ansteuern
  if (laufindex == 1) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
  } else if (laufindex == 2) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
  } else if (laufindex == 3) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
  } else if (laufindex == 4) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, HIGH);
    digitalWrite(LED5_PIN, LOW);
  } else if (laufindex == 5) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, HIGH);
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
  }

}