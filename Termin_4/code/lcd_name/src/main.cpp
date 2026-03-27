#include <Arduino.h>
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// Display Objekt erzeugen
// Adresse, Anzahl Zeichen, Anzahl Spalten
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();         // LCD initialisieren
  lcd.backlight();    // Hintergrundbeleuchtung einschalten
}

void loop() {
  lcd.setCursor(0, 0);    // Erste Spalte, Erste Zeile
  lcd.print("Lukas");
  lcd.setCursor(0, 1);    // Erste Spalte, Zweite Zeile
  lcd.print("Dietz");
}