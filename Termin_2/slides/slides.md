---
# try also 'default' to start simple
theme: neversink
color: green-light
title: Arduino Anfängerkurs - Termin 2
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

<!--
# Check-In Frage

## witzig/kreativ
- Wenn du eine Zeitmaschine hättest, wo würdest du hinreisen?
- Was darf in deinem Kühlschrank nie leer werden?
- Wenn du ein Tier wärst - welches?

## klassisch
- Worauf freust du dich heute?
- Was willst du heute schaffen?
-->

---

# Rückblick - Was haben wir letztes Mal gemacht?

Was stimmt hier nicht? 

```cpp {all|2|5|6|all}
void setup() {
  pinmode(13, OUTPUT);    // Pin als Ausgang setzen

void loop() {
  digitalwrite(13, HIGH);
  delay(1000)
  digitalWrite(13, LOW);
  delay(1000);
}
```

<!--
# Folien sind klickbar!
1. Zeile 2 -> pinMode statt pinmode
2. Zeile 5 -> digitalWrite statt digitalwrite
3. Zeile 6 -> fehlender Strichpunkt
4. Zeile 3 -> fehlende }
-->

---
---

# Heute

- Digitale Eingaben lesen
- Entscheidungen treffen mit `if` / `else`
- LED mit Taster steuern

---
layout: image-right
image: /img/Arduino-Taster-Button.jpg
background-size: 30em
---

# Der Taster

## (Heft S. 7-8)

<v-clicks>

- Digitale Signale haben nur **zwei Zustände**
  - HIGH = 5V
  - LOW = 0V (GND)
- Taster zwischen Pin und GND
- Interner oder externer Pull-Up/Down Widerstand

</v-clicks>

<!--
Im Kurs verwenden wir oft den internen Pull-Up.

- Funktioniert NICHT an PIN 13 wegen der internen LED mit Vorwiderstand!
- Für später: Im Datenblatt nachschauen, welche PINs interne Pull-Widerstände haben
-->

---

# pinMode(), digitalRead() und digitalWrite()

````md magic-move {lines: true}
```cpp {*}
// Aus Termin 1 kennen wir das schon:
pinMode(pin, OUTPUT);
digitalWrite(pin, HIGH);  // oder LOW
```

```cpp {*}
// Aus Termin 1 kennen wir das schon:
pinMode(pin, OUTPUT);
digitalWrite(pin, HIGH);  // oder LOW

// Neu heute:
pinMode(pin, INPUT_PULLUP);   // Pin als Eingang mit Pull-Up
digitalRead(pin);             // Liefert HIGH oder LOW zurück
```
````

<br>

<v-click>

> **Achtung:** Bei `INPUT_PULLUP` bedeutet gedrückt = **LOW**!

</v-click>

<!--
# Folie ist klickbar!

1. Was kennen wir bereits
2. Was ist neu
3. Hinweis
-->

---
layout: image-left
image: /img/pull_up_down.png
background-size: 30em
---

# Pull-Up/ Pull-Down Widerstand

<v-clicks>

- Ein offener Pin "floatet" – er nimmt zufällige Werte an
- Der Pull-Up Widerstand zieht den Pin auf HIGH, wenn nichts angeschlossen ist
- Der Pull-Down Widerstand zieht den Pin auf LOW, wenn nichts angeschlossen ist

</v-clicks>

<!--
Eventuell den Stromfluss einmal aufzeichnen und klar machen, wo der Unterschied liegt.
-->

---
layout: image-right
image: /img/pull_up.png
background-size: 20em
---

# Interner Pull-Up Widerstand

<v-clicks>

- Widerstand R2 ist im Arduino eingebaut
- Taster zwischen GND und Pin anschließen

> Pull-Up aktivieren: `pinMode(13, INPUT_PULLUP);`
> Eingang abfragen: `digitalRead(13);`

</v-clicks>

<!--
# Folie ist klickbar!
1. Physischer Aufbau
2. Programmierung
-->

---

# Bedingungen mit if / else

````md magic-move {at: 1}

```cpp
if (Bedingung) {
  // Wird ausgeführt, wenn Bedingung WAHR ist
} else {
  // Wird ausgeführt, wenn Bedingung FALSCH ist
}
```

```cpp
if (Bedingung) {
  // Wird ausgeführt, wenn Bedingung WAHR ist
} else {
  // Wird ausgeführt, wenn Bedingung FALSCH ist
}

if (helligkeit > 500) {
  digitalWrite(LED_PIN, HIGH);
} else {
  digitalWrite(LED_PIN, LOW);
}

```

```cpp
if (Bedingung) {
  // Wird ausgeführt, wenn Bedingung WAHR ist
} else {
  // Wird ausgeführt, wenn Bedingung FALSCH ist
}
```

````

<v-click at="3">

Vergleichsoperatoren:

| Operator | Bedeutung |
| -------- | --------- |
| `==` | gleich |
| `!=` | ungleich |
| `>` / `<` | größer / kleiner |
| `>=` / `<=` | größer-gleich / kleiner-gleich |

</v-click>

<!--
# Folie ist klickbar!

1. Theorie
2. Beispiel
3. Theorie
4. Vergleichsoperatoren
-->

---
---

# Häufiger Fehler: `=` vs. `==`

```cpp
int x = 5;   // = ist eine ZUWEISUNG – x bekommt den Wert 5

if (x == 5) {   // == ist ein VERGLEICH – ist x gleich 5?
  // ...
}

if (x = 5) {   // FALSCH! Das ist eine Zuweisung, kein Vergleich!
  // ...
}
```

---
layout: statement
---

# Noch Fragen?

---
layout: image-left
image: /img/led_taster.png
background-size: 30em
---

# LED mit Taster steuern

<v-clicks>

- Taster an Pin 12 und GND
- LED + 220Ω Widerstand an Pin 11 und GND
- Solange der Taster gedrückt ist → LED leuchtet
<br><br>
- **Schaltung aufbauen und Programm schreiben → Los gehts!**

</v-clicks>

<!--
Konkrete Uhrzeit auf Folie schreiben!

Je nach Fortschritt der Gruppe ca. 20 Min.

=> Hilfestellung in Form von Codegerüst auf nächster Folie
-->

---
---

# Code-Gerüst: LED mit Taster

```cpp
const int PIN_TASTER = 2;
const int PIN_LED = 9;

void setup() {
  pinMode(PIN_TASTER, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tasterZustand = digitalRead(PIN_TASTER);

  // TODO: if/else Logik ergänzen
  // Wenn Taster gedrückt (= LOW) -> LED an
  // Sonst -> LED aus

  // TODO: Zustand auf seriellem Monitor ausgeben
}
```

---
layout: statement
---

# Warum ist gedrückt = LOW <br> und nicht HIGH?

<!--
Es soll sichergestellt werden, dass alle Teilnehmer das Konzept von Pull-Up und Pull-Down verstanden haben.

Ggf. noch fragen "**Was muss ich tun, damit gedrückt = HIGH ist?**"
-->

---
---

# Erweiterung 1 - Toggle-Funktion

**Ziel:** Bei jedem Tastendruck wechselt die LED ihren Zustand (an → aus → an → aus)

**Tipp:** Du solltest den Zustand der LED speichern

---
---

# Erweiterung 1 - Toggle-Funktion - Lösung

```cpp
bool ledZustand = false;   // Zustandsspeicher

void loop() {
  if (digitalRead(PIN_TASTER) == LOW) {
    ledZustand = !ledZustand;   // Zustand umkehren
    digitalWrite(PIN_LED, ledZustand);
    delay(50);   // Einfache Entprellung
  }
}
```

<v-click>

<br>

> **Hinweis:** Die LED schaltet manchmal mehrmals – das ist das **Prellen** des Tasters!

</v-click>

---
layout: statement
---

# Erweiterung 2 - Software-Entprellung

Damit ein Tastendruck erkannt wird muss der Taster für mindestens 100ms gedrückt sein!

<!--
Teilnehmer sollen jetzt selbstständig nach einer geeigneten Lösung suchen!

Es gibt hier mehrere Lösungen!
Die Lösung auf der nächsten Folie ist nicht die einzige richtige.

### Konkrete Uhrzeit auf Folie schreiben
Zeitansatz: ca. 15 min
-->

---

# Erweiterung 2 - Software-Entprellung - Lösungsvorschlag

```cpp
if (digitalRead(PIN_TASTER) == LOW) {
  delay(100);                            // Warte 100ms
  if (digitalRead(PIN_TASTER) == LOW) {  // Immer noch gedrückt?
    // Echter Tastendruck -> Aktion ausführen
  }
}
```

<v-click>

<br>

> Was wäre, wenn du `delay(100)` nicht verwenden kannst, weil der Arduino in dieser Zeit noch andere Dinge tun muss? Das lösen wir im Fortgeschrittenenkurs!

</v-click>

<!--
Wenn es Teilnehmer gibt die schon die Funktion millis() kennen sollten wir auf den Fortgeschrittenenkurs verweisen und nichts vorgreifen.

Das mag zwar im ersten Moment sinnvoll sein, allerdings läuft uns dann im Fortgeschrittenenkurs die Gruppe vom Wissensstand noch mehr auseinander!
-->

---
layout: two-cols-header
---

# Zusatzaufgabe - Ampelschaltung

::left::

### Aufbau

- Rote, gelbe und grüne LED
  - Rot => Pin 13
  - Gelb => Pin 12
  - Grün => Pin 11
- Jede LED mit passendem Vorwiderstand
- Zeiten wie bei echter Ampel

::right::

### Ablauf

| Phase | Farbe | Zeit |
| ----- | ----- | ---- |
| Stop | Rot | 3000ms |
| Achtung | Rot + Gelb | 1000ms |
| Fahrt | Grün | 3000ms |
| Bremsen | Gelb | 1000ms |

<style>
.two-cols-header {
  column-gap: 20px;
}
</style>

<!--
## Hier brauchen wir keine konkreten Zeiten mehr

Jeder Teilnehmer bearbeitet Zusatzaufgaben im eigenen Tempo
-->

---
layout: two-cols-header
---

# Zusatzaufgabe - Fußgängerampel

::left::

### Aufbau

- Zusätzlich rote und grüne LED für Fußgänger
  - Rot => Pin 10
  - Grün => Pin 9
- Taster für Fußgänger
  - Pin 8

::right::

### Ablauf

Zusätzlich zur normalen Ampel:

- Wenn der Taster gedrückt wurde läuft die Ampel normal weiter, bis das nächste mal rot kommt
- Beide Ampeln müssen für 500ms rot sein
- Fußgängerampel für 3000ms grün
- Beide Ampeln für 500ms rot
- Auto-Ampel läuft bei gelb weiter

<style>
.two-cols-header {
  column-gap: 20px;
}
</style>

---

# Challenge - Türklingel mit Bestätigung

> Bei dieser Aufgabe musst du wirklich knobeln - Also lass dich nicht unterkriegen!

<br>

**Ziel:** Du simulierst eine Türklingel mit Türöffner

- Wird Taster 1 (Klingel) gedrückt, blinkt eine rote LED langsam
- Wird Taster 2 (Türöffner) gedrückt, geht die rote LED aus und eine grüne LED blinkt kurz
- Wird Taster 2 nicht innerhalb von ca. 5 Sekunden gedrückt, blinkt die rote LED schneller

**Aufgaben:**

- Zeichne einen Schaltplan auf Papier
- Baue die Schaltung auf deinem Breadboard auf
- Programmiere die Logik

---
layout: full
---

# Zusammenfassung

<StickyNote color="amber-light" width="220px" title="Digitale Eingabe" v-drag="[100, 120, 220, 140]" style="transform: rotate(-3deg)">

  - `pinMode(pin, INPUT_PULLUP)`
  - `digitalRead(pin)` → HIGH oder LOW
</StickyNote>

<StickyNote color="pink-light" width="240px" title="Pull-Up Widerstand" v-drag="[350, 100, 240, 140]" style="transform: rotate(2deg)">

  - Pin wird auf HIGH gezogen
  - Gedrückt = LOW!
</StickyNote>

<StickyNote color="teal-light" width="260px" title="if / else" v-drag="[620, 130, 260, 140]" style="transform: rotate(-4deg)">

  - `==` zum Vergleichen, nicht `=`
  - `else` für den anderen Fall
</StickyNote>

<StickyNote color="green-light" width="240px" title="Taster-Schaltung" v-drag="[180, 320, 240, 130]" style="transform: rotate(3deg)">

  - Taster zwischen Pin und GND
  - `INPUT_PULLUP` verwenden
</StickyNote>

<StickyNote color="sky-light" width="240px" title="Entprellung" v-drag="[490, 340, 240, 130]" style="transform: rotate(-2deg)">

  - Taster prellen beim Drücken
  - `delay(100)` als einfache Lösung
</StickyNote>
