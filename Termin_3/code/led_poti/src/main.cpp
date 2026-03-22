#include <Arduino.h>

int POTI_PIN = A0;
int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorwert = analogRead(POTI_PIN);

  int helligkeit = map(sensorwert, 0, 1023, 0, 255);

  analogWrite(LED_PIN, helligkeit);

  Serial.print("Sensor: ");
  Serial.print(sensorwert);
  Serial.print("  |  LED: ");
  Serial.println(helligkeit);

  delay(50);
}