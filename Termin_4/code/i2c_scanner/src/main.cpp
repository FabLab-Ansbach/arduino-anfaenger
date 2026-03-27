#include <Arduino.h>
#include "Wire.h"

void setup() {
  Serial.begin(9600);

  Wire.begin(); // I2C Schnittstelle starten
  Serial.print("I2C Scanner");
  Serial.println("***********");
}

void loop() {
  byte fehler;
  byte adresse;
  int anzahlGeraete;

  Serial.println("Scannen...");

  anzahlGeraete = 0;
  // Alle möglichen Adressen durchgehen
  for (adresse = 1; adresse < 127; adresse++) {
    Wire.beginTransmission(adresse);
    fehler = Wire.endTransmission();

    // Wenn kein Fehler passiert ist gibt es ein Gerät mit der Adresse
    if (fehler == 0) {
      Serial.print("I2C Gerät gefunden bei Adresse 0x");
      if (adresse < 16) {
        Serial.print("0");
      }
      Serial.print(adresse, HEX);
      Serial.println(" !");

      anzahlGeraete++;
    }
    // Gerät hat mit Fehler geantwortet
    else if (fehler == 4) {
      Serial.print("Unbekannter Fehler bei Adresse 0x");
      if (adresse < 16) {
        Serial.print("0");
      }
      Serial.print(adresse, HEX);
      Serial.println(" !");
    }
  }
  if (anzahlGeraete == 0) {
    Serial.println("Keine I2C Geräte gefunden!");
  }
  Serial.print("Scannen abgeschlossen");
  Serial.print("*********************");
  Serial.println("");
}