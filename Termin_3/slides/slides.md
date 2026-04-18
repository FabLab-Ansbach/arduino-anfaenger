---
# try also 'default' to start simple
theme: neversink
color: green-light
title: Arduino Anfängerkurs - Termin 3
info: FabLab Ansbach e.V. 2025
author: Lukas Dietz
class: text-center
# https://sli.dev/features/drawing
drawings:
  persist: false
# slide transition: https://sli.dev/guide/animations.html#slide-transitions
transition: slide-left
# enable MDC Syntax: https://sli.dev/features/mdc
mdc: true
layout: cover
---

---
---

# Rückblick - LED anschließen

Ihr habt **2 Minuten** Zeit:

- Schließt eine LED mit passendem Vorwiderstand an den Arduino an
- Kein Code – nur Hardware!

---
---

# Heute

- Analoge Signale lesen und ausgeben
- PWM – Wie der Arduino "Spannung regeln" kann
- Die `map()`-Funktion
- `for`-Schleifen

---
---

# Digital vs. Analog

| | Digital | Analog |
| --- | --- | --- |
| Beispiel | Lichtschalter | Dimmer |
| Zustände | AN oder AUS | Stufenlos |
| Arduino lesen | `digitalRead()` → 0 oder 1 | `analogRead()` → 0 bis 1023 |
| Arduino schreiben | `digitalWrite()` → HIGH/LOW | `analogWrite()` → 0 bis 255 |

---
---

# analogRead() - Spannung messen

````md magic-move {lines: true}
```cpp {*}
// Wert vom analogen Pin lesen
int sensorwert = analogRead(A0);
```

```cpp {*}
// Wert vom analogen Pin lesen
int sensorwert = analogRead(A0);

// sensorwert ist jetzt zwischen 0 und 1023
// 0    entspricht 0V
// 1023 entspricht 5V

Serial.println(sensorwert);
```
````

---
---

# analogWrite() - Spannung ausgeben

```cpp
// Wert zwischen 0 (aus) und 255 (volle Helligkeit)
analogWrite(9, 128);    // ~halbe Helligkeit
analogWrite(9, 255);    // volle Helligkeit
analogWrite(9, 0);      // aus
```

---
---

# PWM – Pulsweitenmodulation

<v-clicks>

- Der Arduino kann nur 0V oder 5V ausgeben
- Stattdessen: sehr schnelles An- und Ausschalten
- Je länger "AN" → desto heller wirkt die LED

</v-clicks>

<v-click>

```
Vollgas  (255): ████████████████████  = 5V
Halbgas  (128): ██████████            = ~2.5V
Aus      (  0):                       = 0V
```

</v-click>

<v-click>

<br>

> Nur an Pins mit **`~`** Symbol möglich: 3, 5, 6, 9, 10, 11 beim UNO

</v-click>

---
---

# Das Problem: 0-1023 → 0-255

<v-clicks>

- `analogRead()` liefert **0 bis 1023**
- `analogWrite()` erwartet **0 bis 255**
- Wir brauchen eine Umrechnung!

</v-clicks>

<v-click>

```cpp
// Selbst rechnen – umständlich:
int helligkeit = sensorwert / 4;   // grob, ungenau
```

</v-click>

<br>

<v-click>

```cpp
// Besser: map() verwenden!
int helligkeit = map(sensorwert, 0, 1023, 0, 255);
```

</v-click>

---
---

# Die map()-Funktion

```cpp
map(wert, vonMin, vonMax, zuMin, zuMax)
```

<v-click>

Beispiel:

```cpp
// Potentiometer-Wert (0-1023) auf LED-Helligkeit (0-255) umrechnen
int helligkeit = map(sensorwert, 0, 1023, 0, 255);

// Oder umgekehrt: Poti dreht LED dunkler statt heller
int helligkeit = map(sensorwert, 0, 1023, 255, 0);
```

</v-click>

---
---

# Die for-Schleife

```cpp
for (int i = 0; i < 10; i++) {
  // Wird 10-mal ausgeführt
  Serial.println(i);
}
```

<v-click>

Die drei Teile:

| Teil | Beispiel | Bedeutung |
| ---- | -------- | --------- |
| Initialisierung | `int i = 0` | Startwert |
| Bedingung | `i < 10` | Solange ausführen wie |
| Inkrement | `i++` | i nach jedem Durchlauf um 1 nach oben zählen |

</v-click>

---
layout: image-right
image: /img/Potentiometer.jpg
background-size: 25em
---

# Das Potentiometer

## (Heft S. 8, Material Nr. 24)

<v-clicks>

- Drei Anschlüsse:
  - Außen links → **5V**
  - Außen rechts → **GND**
  - Mitte → **Analoger Pin**
- Was passiert, wenn man am Knopf dreht?

</v-clicks>

---
layout: statement
---

# Noch Fragen?

---
layout: image-left
image: /img/led_poti.png
background-size: 30em
---

# LED mit Potentiometer dimmen

<v-clicks>

- Potentiometer: Links → GND, Rechts → +5V, Mitte → A0
- LED + 220Ω an Pin **9** (PWM!) und GND
- **Schaltung aufbauen und Code ergänzen → Los gehts!**

</v-clicks>

---
---

# Code-Gerüst: LED dimmen

```cpp
int POTI_PIN = A0;
int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorwert = analogRead(POTI_PIN);

  // TODO: map() verwenden um 0-1023 auf 0-255 umzurechnen
  int helligkeit = // ...

  // TODO: LED mit passender Helligkeit ansteuern

  Serial.print("Sensor: ");
  Serial.print(sensorwert);
  Serial.print("  |  LED: ");
  Serial.println(helligkeit);

  delay(50);
}
```

---
---

# Experimentiert! (10 Minuten)

- Was passiert, wenn du die letzten beiden Werte in `map()` vertauschst?
  - `map(sensorwert, 0, 1023, 255, 0)` statt `map(sensorwert, 0, 1023, 0, 255)`
- Kannst du die LED so programmieren, dass sie nur leuchtet, wenn das Poti über der Mitte steht?

---
layout: image-right
image: /img/Photoresistor.jpg
background-size: 20em
---

# Der Fotowiderstand (LDR)

## (Material Nr. 23)

<v-clicks>

- Widerstand ändert sich je nach Helligkeit
- Helles Licht → kleiner Widerstand (~1-2 kΩ)
- Dunkelheit → großer Widerstand (~10-100 kΩ)
- Schaltung als **Spannungsteiler**: LDR + 10kΩ Widerstand

</v-clicks>

<v-click>

> Genaue Werte findet ihr auf dem Info-Blatt!

</v-click>

---
layout: image-left
image: /img/ldr.png
background-size: 30em
---

# Erweiterung - Nachtlicht mit LDR

**Ziel:** Je dunkler es wird, desto heller leuchtet die LED automatisch

- LED => Pin 9 (PWM!)
  - Vorwiderstand je nach Farbe aus Tabelle
- LDR => Pin A0
  - 10 kΩ Widerstand

> Kannst du die LED so programmieren, dass sie nur leuchtet, wenn es dunkel genug ist?

---
---

# Nachtlicht - Lösungsansatz

```cpp
int licht = analogRead(LDR_PIN);

// Invertieren: Bei Dunkelheit soll LED hell sein
int ledHelligkeit = map(licht, 0, 1023, 255, 0);

analogWrite(LED_PIN, ledHelligkeit);
```

<v-click>

**Zusatz:** Ab welchem Schwellwert soll die LED überhaupt angehen?

```cpp
if (licht < 500) {
  analogWrite(LED_PIN, ledHelligkeit);
} else {
  analogWrite(LED_PIN, 0);
}
```

</v-click>

---

# Zusatzaufgabe - Bargraph im Seriellen Monitor

**Ziel:** Der Sensorwert wird als visueller Balken dargestellt

```
[##########          ] 512
[#####               ] 256
[####################] 1023
```

<br>

**Aufgabe:**

- Lest den Wert des Potentiometers oder LDR aus
- Gebt ihn als Balken aus `#`-Zeichen im Seriellen Monitor aus
- Gesamtbreite des Balkens: 20 Zeichen
- Nutzt eine `for`-Schleife!

---
---

# Zusatzaufgabe - Bargraph - Lösungsansatz

```cpp
void loop() {
  int wert = analogRead(A0);
  int balken = map(wert, 0, 1023, 0, 20);

  Serial.print("[");
  for (int i = 0; i < 20; i++) {
    if (i < balken) {
      Serial.print("#");
    } else {
      Serial.print(" ");
    }
  }
  Serial.print("] ");
  Serial.println(wert);

  delay(100);
}
```

---
layout: statement
---

# Challenge <br> - <br> Automatische Kalibrierung

Beim Start misst der Arduino 5 Sekunden lang die Helligkeit und setzt Minimal- und Maximalwert fest!

---
---

# Challenge - Automatische Kalibrierung

```cpp
int minWert = 1023;   // Warum startest du hier mit 1023?
int maxWert = 0;      // Und hier mit 0?

void setup() {
  Serial.begin(9600);
  Serial.println("Kalibrierung läuft 5 Sekunden...");

  for (int i = 0; i < 100; i++) {   // 100 x 50ms = 5 Sekunden
    int wert = analogRead(A0);
    if (wert < minWert) { minWert = wert; }
    if (wert > maxWert) { maxWert = wert; }
    delay(50);
  }
  Serial.println("Fertig!");
}

void loop() {
  int wert = analogRead(A0);
  int helligkeit = map(wert, minWert, maxWert, 0, 255);
  analogWrite(9, helligkeit);
}
```

---
layout: full 
---

# Zusammenfassung

<StickyNote color="amber-light" width="220px" title="analogRead()" v-drag="[100, 120, 220, 140]" style="transform: rotate(-3deg)">

  - Liest Werte von **0 bis 1023**
  - 0 = 0V, 1023 = 5V
</StickyNote>

<StickyNote color="pink-light" width="240px" title="PWM / analogWrite()" v-drag="[350, 100, 240, 140]" style="transform: rotate(2deg)">

  - Nur an `~` Pins (3,5,6,9,10,11)
  - Werte von **0 bis 255**
</StickyNote>

<StickyNote color="teal-light" width="260px" title="map()" v-drag="[620, 130, 260, 130]" style="transform: rotate(-4deg)">

  - Rechnet Wertebereiche um
  - `map(wert, 0, 1023, 0, 255)`
</StickyNote>

<StickyNote color="green-light" width="240px" title="for-Schleife" v-drag="[180, 320, 240, 140]" style="transform: rotate(3deg)">

  - `for (int i = 0; i < n; i++)`
  - Initialisierung, Bedingung, Inkrement
</StickyNote>

<StickyNote color="sky-light" width="240px" title="Fotowiderstand (LDR)" v-drag="[490, 340, 240, 130]" style="transform: rotate(-2deg)">

  - Widerstand ändert sich mit Licht
  - Spannungsteiler mit 10kΩ
</StickyNote>
