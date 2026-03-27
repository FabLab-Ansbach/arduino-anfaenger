#include <Arduino.h>
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// Display Objekt erzeugen
// Adresse, Anzahl Zeichen, Anzahl Spalten
LiquidCrystal_I2C lcd(0x27, 16, 2);

int TASTER_PIN = 10;
int wartezeit = 0;
bool start = false;
int zeit;

void setup() {
  lcd.init();         // LCD initialisieren
  lcd.backlight();    // Hintergrundbeleuchtung einschalten

  randomSeed(analogRead(A0));   // Zufallsgenerator initialisieren

  pinMode(TASTER_PIN, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("Bereit...");
}

void loop() {

  // Tastendruck einlesen
  if (digitalRead(TASTER_PIN) == LOW && !start) {   // Taster wurde gedrückt
    start = true;
  }

  if (start == true) {
    lcd.clear();    // LCD leeren
    wartezeit = random(1000, 10000);  // Zufällige Zeit zwischen 1s und 10s
    lcd.setCursor(0, 0);
    lcd.print("Bereit...");
    delay(wartezeit);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("JETZT!");
    int zeit = 0;

    // Solange Taster nicht gedrückt ist wird die Zeit in 10ms Schritten hochgezählt
    while (digitalRead(TASTER_PIN) == HIGH) {
      zeit = zeit + 10;
      delay(10);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(zeit);
    lcd.setCursor(14, 0);
    lcd.print("ms");

    delay(1000);
  }

}