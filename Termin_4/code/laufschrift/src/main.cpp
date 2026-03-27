#include <Arduino.h>
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// LCD initialisieren (Adresse, Spalten, Zeilen)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Text für Laufschrift
String text = "   Hallo Welt! Das ist eine Laufschrift!   ";

int position = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);

  // 16 Zeichen anzeigen (Displaybreite)
  for (int i = 0; i < 16; i++) {
    int index = position + i;        // aktuelle Position im Text berechnen
    int laenge = text.length();      // Länge des Textes holen

    // Wenn Index größer als Textlänge → wieder von vorne anfangen
    if (index >= laenge) {
      index = index - laenge;
    }

    // Zeichen an dieser Stelle ausgeben
    char zeichen = text[index];
    lcd.print(zeichen);
  }

  position++;

  // Wenn Ende erreicht → wieder von vorne
  if (position >= text.length()) {
    position = 0;
  }

  delay(300); // Geschwindigkeit der Laufschrift
}