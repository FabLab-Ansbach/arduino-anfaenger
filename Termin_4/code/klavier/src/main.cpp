#include <Arduino.h>
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// Display Objekt erzeugen
// Adresse, Anzahl Zeichen, Anzahl Spalten
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins festlegen
int TASTER_C = 2;
int TASTER_D = 3;
int TASTER_E = 4;
int TASTER_F = 5;
int TASTER_G = 6;
int BUZZER_PIN = 9;

// Noten definieren
const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int G = 392;

void setup() {
  lcd.init();         // LCD initialisieren
  lcd.backlight();    // Hintergrundbeleuchtung einschalten

  pinMode(TASTER_C, INPUT_PULLUP);
  pinMode(TASTER_D, INPUT_PULLUP);
  pinMode(TASTER_E, INPUT_PULLUP);
  pinMode(TASTER_F, INPUT_PULLUP);
  pinMode(TASTER_G, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("Klavier");
  lcd.setCursor(0, 1);
  lcd.print("starten...");
  delay(1000);
  lcd.clear();

}

void loop() {

  if (digitalRead(TASTER_C) == LOW) {
    tone(BUZZER_PIN, C);
    lcd.setCursor(0, 0);
    lcd.print("Note C");
    lcd.setCursor(0, 1);
    lcd.print(C);
    lcd.print(" Hz");
  } else if (digitalRead(TASTER_D) == LOW) {
    tone(BUZZER_PIN, D);
    lcd.setCursor(0, 0);
    lcd.print("Note D");
    lcd.setCursor(0, 1);
    lcd.print(D);
    lcd.print(" Hz");
  } else if (digitalRead(TASTER_E) == LOW) {
    tone(BUZZER_PIN, E);
    lcd.setCursor(0, 0);
    lcd.print("Note E");
    lcd.setCursor(0, 1);
    lcd.print(E);
    lcd.print(" Hz");
  } else if (digitalRead(TASTER_F) == LOW) {
    tone(BUZZER_PIN, F);
    lcd.setCursor(0, 0);
    lcd.print("Note F");
    lcd.setCursor(0, 1);
    lcd.print(F);
    lcd.print(" Hz");
  } else if (digitalRead(TASTER_G) == LOW) {
    tone(BUZZER_PIN, G);
    lcd.setCursor(0, 0);
    lcd.print("Note G");
    lcd.setCursor(0, 1);
    lcd.print(G);
    lcd.print(" Hz");
  } else {
    noTone(BUZZER_PIN);
    lcd.clear();
  }

}