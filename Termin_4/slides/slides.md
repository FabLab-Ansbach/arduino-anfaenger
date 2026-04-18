---
# try also 'default' to start simple
theme: neversink
color: green-light
title: Arduino Anfängerkurs - Termin 4
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

# Rückblick - Digital oder Analog?

Daumen **hoch** = analog / Daumen **runter** = digital

<v-clicks>

- 💡 LED
- 🎛️ Potentiometer
- 🔘 Taster
- ☀️ LDR (Fotowiderstand)

</v-clicks>

---
---

# Heute

- Töne ausgeben mit dem Buzzer
- Text auf einem LCD-Display anzeigen
- I²C – Wie Geräte miteinander kommunizieren

---
layout: image-right
image: /img/piezo.webp
background-size: 20em
---

# Der Buzzer (Piezospeaker)

## (Material Nr. 27)

<v-clicks>

- Eine Membran schwingt durch elektrische Impulse
- **Passiver Buzzer:** Braucht eine Frequenz von außen
- Positiver Pin → Pin 8, Negativer Pin → GND

</v-clicks>

---
---

# tone() und noTone()

````md magic-move {lines: true}
```cpp {*}
// Ton starten – läuft bis noTone() aufgerufen wird
tone(pin, frequenz);

// Ton für bestimmte Zeit spielen (in ms)
tone(pin, frequenz, dauer);
```

```cpp {*}
// Ton starten – läuft bis noTone() aufgerufen wird
tone(pin, frequenz);

// Ton für bestimmte Zeit spielen (in ms)
tone(pin, frequenz, dauer);

// Ton stoppen
noTone(pin);
```
````

---
---

# Notenwerte als Frequenzen

| Note | Frequenz |
| ---- | -------- |
| C4 | 262 Hz |
| D4 | 294 Hz |
| E4 | 330 Hz |
| F4 | 349 Hz |
| G4 | 392 Hz |
| A4 | 440 Hz |

---
layout: image-right
image: /img/piezo_schaltung.png 
background-size: 30em
---

# Pflichtprojekt - Melodie spielen

Aufgabe: Spielt die ersten Töne von **Hänschen klein** ab, wenn ein Taster gedrückt wird:

```
G - E - E - F - D - D
```

<br>

**Experimentiert:**
- Kannst du die nächsten Töne selbst ergänzen?
- Was passiert, wenn du die Dauern veränderst?

---
layout: image-left
image: /img/lcd.webp
background-size: 30em
---

# Das LCD-Display

## (Heft S. 64, Material Nr. 28)

<v-clicks>

- 16 Zeichen × 2 Zeilen
- Anschluss über nur **4 Drähte** dank I²C:
  - VCC → 5V
  - GND → GND
  - SDA → A4
  - SCL → A5

</v-clicks>

---
---

# Schritt 1 - I²C-Scanner übertragen

1. Schaltung aufbauen (VCC, GND, SDA → A4, SCL → A5)
2. Das vorbereitete **I²C-Scanner-Projekt** übertragen
3. Seriellen Monitor öffnen
4. **Schreib die Adresse von deinem Display auf!** (z.B. 0x27 oder 0x3F)

---
---

# Was ist I²C?

<v-clicks>

- **Inter-Integrated Circuit** – ein Kommunikationsprotokoll
- Nur **zwei Drähte** verbinden mehrere Geräte:
  - **SDA** – Datenleitung
  - **SCL** – Taktleitung
- SDA mit SDA verbinden und SCL mit SCL verbinden
- Benutzt die **Wire** Bibliothek
- Jedes Gerät hat eine **eindeutige Adresse**
- Deshalb hat jedes Display eine andere Adresse – daher der Scanner!

</v-clicks>

---
---

# Bibliotheken einbinden

> Bibliotheken stellen zusätzliche Funktionen zur Verfügung

<br>

#### In platformio.ini eintragen

```ini {*|7-9}
[env:uno]
platform = atmelavr
board = uno
framework = arduino
monitor_speed = 9600

lib_deps = 
    LiquidCrystal_I2C
    https://github.com/johnrickman/LiquidCrystal_I2C
```

<br>

> Alle Bibliotheken bei **lib_deps** angeben - Eine Bibliothek pro Zeile 

---
---

# Bibliotheken einbinden

#### Im Programm einbinden

```cpp
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
```

<br>

- Mit `#include` bindest du eine Bibliothek in dein Programm ein
- Erst danach kannst du Funktionen aus der Bibliothek verwenden
- Nur das eintragen in der **platformio.ini** reicht nicht!

---
---

# Schritt 2 - Name auf dem Display anzeigen

```cpp
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse, Spalten, Zeilen

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);     // Spalte 0, Zeile 0
  lcd.print("Hallo!");

  lcd.setCursor(0, 1);     // Spalte 0, Zeile 1
  lcd.print("Ich bin ...");
}
```

<v-click>

Trage deine **eigene I²C-Adresse** ein und schreibe deinen Namen auf das Display → Los gehts!

</v-click>

---
---

# Erweiterung 1 - Reaktionstest

#### Aufgabe:

<br>

1. Display zeigt "Bereit..." an
2. Nach einer zufälligen Zeit erscheint "JETZT!"
3. Der Spieler muss so schnell wie möglich den Taster (**Pin 10**) drücken
4. Danach wird die gemessene Zeit angezeigt
5. Wird der Taster (**Pin 10**) wieder gedrückt beginnt das Spiel von vorne

#### Hinweise:

- verwende `randomSeed(analogRead(A0));` in deiner Setup-Funktion
- `random(min, max);` gibt dir eine zufällige Zahl zwischen min und max zurück

---
---

# Erweiterung 2 - Eieruhr

**Aufbau:**

- Zwei Taster: Minuten hoch (**PIN 10**) / Minuten runter (**PIN 11**)
- Ein Taster: Timer starten/stumm schalten (**PIN 12**)
- Buzzer (**PIN 9**) für Alarm
- LCD für Anzeige

<br>

> **Diese Aufgabe kombiniert alles, was du bisher gelernt habt – lass dich nicht unterkriegen!**

---

# Zusatzaufgabe - Mini Klavier

**Ziel:** Jeder Taster spielt eine andere Note – der Ton wird auf dem Display angezeigt

**Schaltung:**
- 5 Taster an Pins 2–6
- Buzzer an Pin 9
- Display wie bisher

<br>

**Aufgabe:**
- Taster 1 → Note C erklingt, Display zeigt `Note: C`
- Taster 2 → Note D erklingt, Display zeigt `Note: D`
- usw. für E, F, G

---
layout: statement
---

# Challenge - Laufschrift

Versuche einen langen Text als Laufschrift anzuzeigen.
<br>

> **Hinweis:** Wenn du Texte als String speicherst kannst du mit [] einzelne Buchstaben daraus bekommen
> ```
> String text = "Hallo Welt";
> char buchstabe = text[1]; // a, weil wir bei 0 anfangen zu zählen
> ```

---
layout: full
---

# Zusammenfassung

<StickyNote color="amber-light" width="220px" title="Buzzer" v-drag="[100, 120, 220, 150]" style="transform: rotate(-3deg)">

  - `tone(pin, frequenz)`
  - `tone(pin, frequenz, dauer)`
  - `noTone(pin)`
</StickyNote>

<StickyNote color="pink-light" width="240px" title="I²C" v-drag="[350, 100, 240, 150]" style="transform: rotate(2deg)">
euch
  - Nur SDA + SCL nötig
  - Jedes Gerät hat eine Adresse
  - Scanner verrät die Adresse
</StickyNote>

<StickyNote color="teal-light" width="260px" title="LCD" v-drag="[620, 230, 260, 150]" style="transform: rotate(-4deg)">

  - `lcd.init()` + `lcd.backlight()`
  - `lcd.setCursor(spalte, zeile)`
  - `lcd.print("Text")`
</StickyNote>

<StickyNote color="green-light" width="240px" title="Libraries" v-drag="[280, 320, 240, 130]" style="transform: rotate(3deg)">

  - `lib_deps` in platformio.ini
  - `#include` im Code
</StickyNote>