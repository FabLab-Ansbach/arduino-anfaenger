#include <Arduino.h>

int LDR_PIN = A0;
int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorwert = analogRead(LDR_PIN);

  int helligkeit = map(sensorwert, 0, 1023, 255, 0);

  if (sensorwert < 500) {     // LED nur einschalten, wenn es auch dunkel ist
    analogWrite(LED_PIN, helligkeit);
  } else {
    analogWrite(LED_PIN, 0);  // Wenn es zu hell ist schalten wir die LED aus
  }

  Serial.print("Sensor: ");
  Serial.print(sensorwert);
  Serial.print("  |  LED: ");
  Serial.println(helligkeit);

  delay(50);
}