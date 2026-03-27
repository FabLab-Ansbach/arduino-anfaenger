#include <Arduino.h>
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// Display Objekt erzeugen
// Adresse, Anzahl Zeichen, Anzahl Spalten
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins festlegen
int TASTER_PLUS = 10;
int TASTER_MINUS = 11;
int TASTER_START = 12;
int BUZZER_PIN = 9;

bool lauft = false;
int zeit = 0;

void setup() {
  lcd.init();         // LCD initialisieren
  lcd.backlight();    // Hintergrundbeleuchtung einschalten

  pinMode(TASTER_MINUS, INPUT_PULLUP);
  pinMode(TASTER_PLUS, INPUT_PULLUP);
  pinMode(TASTER_START, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print(zeit);
  lcd.print(" s");
}

void loop() {

  // Zeit runterzählen
  if (digitalRead(TASTER_MINUS) == LOW && !lauft && zeit >= 1) {
    delay(50);
    if (digitalRead(TASTER_MINUS) == LOW) {
      zeit = zeit - 1;
    }
  }

  // Zeit hochzählen
  if (digitalRead(TASTER_PLUS) == LOW && !lauft) {
    delay(50);
    if (digitalRead(TASTER_PLUS) == LOW) {
      zeit = zeit + 1;
    }
  }

  // Timer nur starten, wenn noch nicht gestartet und Zeit eingestellt
  if (digitalRead(TASTER_START) == LOW && !lauft && zeit > 0) {
    delay(50);
    if (digitalRead(TASTER_START) == LOW) {
      lauft = true;
    }
  }

  // Zeit läuft gerade ab...
  if (lauft) {
    // Solange Zeit noch nicht 0 ist
    // Warte für 1 Sekunde und ziehe 1 von der Restzeit ab
    while (zeit > 0) {
      delay(1000);
      zeit = zeit - 1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(zeit);
      lcd.print(" s");
    }

    // Zeit ist abgelaufen
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Zeit Abgelaufen");
    tone(BUZZER_PIN, 440);    // Ton starten

    // Solange nichts tun bis Taster gedrückt wurde
    while (digitalRead(TASTER_START) == HIGH) {}

    noTone(BUZZER_PIN);       // Ton ausschalten
    lcd.clear();              // Display leeren
    lauft = false;            // Timer zurücksetzen

  }

  // Zeit anzeigen
  lcd.setCursor(0, 0);
  lcd.print(zeit);
  lcd.print(" ms");

}