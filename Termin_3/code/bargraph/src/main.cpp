#include <Arduino.h>

int LDR_PIN = A0;
int LED_PIN = 9;

int minWert = 1023;   // Warum starten wir hier mit 1023?
int maxWert = 0;      // Und hier mit 0?

void setup() {
  Serial.begin(9600);
  Serial.println("Kalibrierung läuft 5 Sekunden...");

  for (int i = 0; i < 100; i++) {   // 100 x 50ms = 5 Sekunden
    int wert = analogRead(LDR_PIN);
    if (wert < minWert) { minWert = wert; }
    if (wert > maxWert) { maxWert = wert; }
    delay(50);
  }
  Serial.println("Fertig!");
}

void loop() {
  int wert = analogRead(LDR_PIN);
  int helligkeit = map(wert, minWert, maxWert, 0, 255);
  analogWrite(LED_PIN, helligkeit);
}