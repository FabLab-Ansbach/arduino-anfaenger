#include <Arduino.h>

int LDR_PIN = A0;
int POTI_PIN = A1;
int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorwert = analogRead(LDR_PIN);
  int grenzwert = analogRead(POTI_PIN);

  int helligkeit = map(sensorwert, 0, 1023, 0, 255);
  int grenzwert = map(grenzwert, 0, 1023, 0, 255);

  if (helligkeit < grenzwert) {
    analogWrite(LED_PIN, 255-helligkeit);
  } else {
    analogWrite(LED_PIN, 0);  // LED ausschalten
  }

  Serial.print("Sensor: ");
  Serial.print(sensorwert);
  Serial.print("  |  Grenzwert: ");
  Serial.println(grenzwert);
  Serial.print("Helligkeit: ");
  Serial.println(helligkeit);

  delay(50);
}