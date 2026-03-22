# Termin 3 - Analoge Signale & Schleifen

**Kapitel im Heft:** Kapitel 2.1.4 (Widerstände), Potentiometer (Material Nr. 24), LDR (Fotowiderstand, Material Nr. 23)

## Rückblick

- **Praktischer Rückblick:** Jede*r schließt in 2 Minuten eine LED mit Vorwiderstand an den Arduino an
- Kein Code – nur Hardware
- Zeigt: Wer hat das Breadboard-Prinzip verstanden?

## Theorie

**Referenz:** Heft Kapitel 2.1.4 (Widerstände), Material Nr. 24 (Potentiometer)

- Unterschied digital und analog
  - Digital: Lichtschalter (an/aus)
  - Analog: Dimmer (stufenlos)
- analoger Eingang: analogRead()
  - Liefert Werte von 0 bis 1023
  - Entspricht 0V bis 5V
  - Live-Demo: Potentiometer auslesen und Werte im Seriellen Monitor zeigen
- PWM (Pulsweitenmodulation)
  - Warum kann der Arduino nicht einfach "3,0 Volt" ausgeben?
  - PWM = sehr schnelles An- und Ausschalten
  - Nur an Pins mit `~` Symbol (3, 5, 6, 9, 10, 11 beim UNO)
  - `analogWrite(pin, wert)` – Wert zwischen 0 und 255
  - Aufbau am Oszi zeigen
- map()-Funktion erklären
  - Problem: `analogRead()` liefert 0-1023, `analogWrite()` braucht 0-255
  - `map(wert, vonMin, vonMax, zuMin, zuMax)`
  - Beispiel live durchrechnen
- for-Schleife
  - Syntax: `for (int i = 0; i < 10; i++) { }`
  - Drei Teile: Initialisierung, Bedingung, Inkrement
- Variablentypen
  - int: Ganze Zahlen (-32768 bis 32767)
  - long: Große ganze Zahlen
  - float: Kommazahlen (z.B. 3.14)
- Potentiometer erklären
  - **Referenz:** Heft Seite 8, Material Nr. 24
  - Drei Anschlüsse: Außen an 5V und GND, Mitte an analogen Pin

## Pflichtprojekt - LED mit Potentiometer dimmen

**Schaltung:**

- Potentiometer: Linker Pin → GND, Rechter Pin → +5V, Mittlerer Pin → A0
- LED + 220Ω an Pin 9 (PWM!) und GND

**Code-Gerüst mit TODO:**

```cpp
int POTI_PIN = A0;
int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);L, hel
}

void loop() {
  int sensorwert = analogRead(POTI_PIN);
  
  // TODO: map() verwenden um 0-1023 auf 0-255 umzurechnen
  int helligkeit = // ...
  
  analogWrite(LED_PIN, helligkeit);
  
  Serial.print("Sensor: ");
  Serial.print(sensorwert);
  Serial.print("  |  LED: ");
  Serial.println(helligkeit);
  
  delay(50);
}
```

**Experimentieraufgaben:**

- Was passiert, wenn du die letzten beiden Werte in `map()` vertauschst? (255, 0 statt 0, 255)
- Kannst du die LED so programmieren, dass sie nur leuchtet, wenn das Poti über der Mitte steht?

## Erweiterung - Nachtlicht mit LDR

**Ziel:** Je dunkler es wird, desto heller leuchtet die LED automatisch.

**LDR-Informationen:**

- Kursleiter stellt ein **einseitiges Info-Blatt** bereit mit den wichtigsten Daten
- Informationen über LDR aus Datenblatt (in Kursordner) herausfinden. Beantworte diese Fragen:
  - Wie groß ist der Widerstand bei hellem Licht (z.B. über 1000 Lux): ca. 1-2 kΩ
  - Wie groß ist der Widerstand bei Dunkelheit: ca. 10-100 kΩ
  - Schaltung als Spannungsteiler: LDR + 10kΩ Widerstand
- Aufbau mit Spannungsteiler
- evtl. Berechnung von Spannungsabfall an Widerstand
- Je dunkler das Licht wird, desto heller wird die LED
- Zusatz: Schwellwert ab dem die LED eingeschalten werden darf

**Logik:**

```cpp
int licht = analogRead(A1);
// Invertieren: Bei Dunkelheit soll LED hell sein
int ledHelligkeit = map(licht, 0, 1023, 255, 0);
ledHelligkeit = constrain(ledHelligkeit, 0, 255);
analogWrite(9, ledHelligkeit);
```

## Challenge - Bargraph für Helligkeit

**Ziel:** Der Wert des Potentiometers oder LDR wird als visueller Balken (`####`) im Seriellen Monitor dargestellt.

**Beispiel-Ausgabe:**

```shell
[##########          ] 512
[#####               ] 256
[####################] 1023
```

**Lernziel:** Erste eigene Funktion mit Parametern, `for`-Schleife in der Praxis

## Zusatzaufgabe - Automatische Kalibrierung

**Für sehr schnelle Teilnehmer*innen.**

Beim Start des Programms misst der Arduino 5 Sekunden lang den Helligkeitswert und speichert den höchsten und niedrigsten gemessenen Wert. Diese Werte werden dann in `map()` verwendet statt 0 und 1023.

**Vorteil:** Der Sensor passt sich automatisch an die Umgebung an.

**Lernziel:** `setup()` als echte Initialisierungsphase, Min/Max-Pattern

**Hinweis:** Startwerte sind `minWert = 1023` und `maxWert = 0` (warum?)
