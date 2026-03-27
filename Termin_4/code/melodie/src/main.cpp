#include <Arduino.h>

// Notenwerte
const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int G = 392;
const int A = 440;

int DAUER = 500;

int TASTER_PIN = 12;
int BUZZER_PIN = 11;

bool abspielen = false;

void setup() {
  Serial.begin(9600);

  pinMode(TASTER_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(TASTER_PIN) == LOW) { // Taster wurde gedrückt
    delay(50);
    if (digitalRead(TASTER_PIN) == LOW && !abspielen) { // Taster ist immer noch gedrückt und Lied spielt gerade nicht
      abspielen = true;
    }
  }

  if (abspielen) {
    tone(BUZZER_PIN, G, DAUER);
    delay(DAUER * 1.30);
    tone(BUZZER_PIN, E, DAUER);
    delay(DAUER * 1.30);
    tone(BUZZER_PIN, E, DAUER);
    delay(DAUER * 1.30);
    tone(BUZZER_PIN, F, DAUER);
    delay(DAUER * 1.30);
    tone(BUZZER_PIN, D, DAUER);
    delay(DAUER * 1.30);
    tone(BUZZER_PIN, D, DAUER);
    delay(DAUER * 1.30);
    noTone(BUZZER_PIN);
    abspielen = false;
  }

}