---
# try also 'default' to start simple
theme: neversink
color: green-light
title: Arduino Anfängerkurs - Termin 1
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
### Auf jedem Platz sollte liegen:
- Laptop + Maus
- Arduino Box
- eine Karteikarte bzw. Zettel min. Din A7
- ein Stift
- ausgedrucktes DIY-Cheatsheet + Code Guidelines
- Projekt blinkende_led in home-Verzeichnis kopiert
-->

---
layout: image
image: /img/fablab_logo.svg
background-size: 30em
---

# Das FabLab

<!--
# Begrüßung + Vorstellung
- Teilnehmer zum Arduinokurs begrüßen
- Kursleiter + Mitarbeiter stellen sich vor
- FabLab vorstellen für alle die es nicht kennen
-->

---
layout: image
image: /img/ANsWERK_Logo.png
background-size: 30em
---

# Das ANsWERK

<!--
### Answerk erwähnen

# Wichtige Infos
## Allgemeines
- WC
- Getränke kostenlos vom AnsWerk wer nichts dabei hat
## Ablauf
Jeder Termin besteht aus:
- Rückblick
- Input
- Aufgaben
- 30 Min. Mittagspause
-->

---
layout: image-left
image: /img/Arduino_Uno.webp
backgroundSize: 30em
---

# Was ist ein Arduino?

<Arrow v-click="[2,3]" x1="550" y1="145" x2="350" y2="340" color="red" width=5 />
<Arrow v-click="[3,4]" x1="550" y1="185" x2="100" y2="200" color="red" width=5 />
<Arrow v-click="[4,5]" x1="550" y1="225" x2="300" y2="150" color="red" width=5 />
<Arrow v-click="[5,6]" x1="550" y1="275" x2="300" y2="400" color="red" width=5 />
<Arrow v-click="[6]" x1="550" y1="320" x2="400" y2="400" color="red" width=5 />

<ul>
  <li v-click="1">Entwicklungsplatine für Mikrocontroller</li>
</ul>

<ul class="ml-6">
  <li v-click="2">Mikrocontroller</li>
  <li v-click="3">USB-Anschluss</li>
  <li v-click="4">Digitale Ein-/Ausgänge</li>
  <li v-click="5">Spannungs Pins</li>
  <li v-click="6">Analoge Eingänge</li>
</ul>

<!--
Teilnehmer fragen: "Wer kennt Arduino oder hat schon was damit gemacht?"
Evtl. Teilnehmer erklären lassen

=> Darauf hinweisen, dass ein Arduino KEIN Mikrocontroller ist, sondern das "Gesamtpaket"
-->

---
layout: image-right
image: /img/Breadboard.png
background-size: 30em
---

# Das Breadboard

## (Heft S. 12-13)

<Arrow v-click="[1,2]" x1="280" y1="138" x2="570" y2="140" color="red" width=5 />
<Arrow v-click="[1,2]" x1="280" y1="138" x2="555" y2="345" color="red" width=5 />
<Arrow v-click="[2,3]" x1="350" y1="218" x2="560" y2="200" color="red" width=5 />
<Arrow v-click="[2,3]" x1="350" y1="218" x2="550" y2="280" color="red" width=5 />

<ul>
  <li v-click="1">Versorgungsschienen <br>=> komplett verbunden</li>
  <li v-click="2">"Signalschienen" <br>=> Immer a-e und f-j verbunden</li>
</ul>

<!--
Gleiches Vorgehen wie beim Arduino
-->

---
layout: image-left
image: /img/led_aufbau.svg
background-size: 15em
---

# Die LED

## (Heft S. 13)

<v-click>

- Haben eine feste Polarität!
- \+ (Anode) = längeres Beinchen
- \- (Kathode) = kürzeres Beinchen oder beim "Kelch"
- Merkhilfe: Mit dem längeren Beinchen kann ich leichter ein + machen als mit dem kürzeren

</v-click>

<!--
# Bevor wir die Stichpunkte zeigen
Jeder Teilnehmer*in nimmt sich eine LED aus dem Kasten und schaut sie sich an. Welche Besonderheiten erkennen wir?

- Ein langes und ein kurzes Beinchen
- Eine flache Seite an der LED
- Im Inneren gibt es einen "Kegel"
-->

---
layout: image-right
image: /img/led_aufbau.svg
background-size: 15em
---

# Typische Vorwiderstände bei 5V (Heft S. 14)

| LED-Farbe | Widerstand |
| --------- | ---------- |
| Weiß | 100 Ohm |
| Rot | 200 Ohm |
| Gelb | 200 Ohm |
| Grün | 100 Ohm |
| Blau | 100 Ohm |
| Infrarot | 100 Ohm |

<!--
Darauf hinweisen, dass die Tabelle auch im Heft steht

Teilnehmer können die Werte auch später noch im Heft finden
-->

---
layout: default

# Überblick über VS-Code mit PlatformIO
---

# Anmeldung am Laptop

- Benutzername: **user** | Passwort: **fablab**
- Keine persönlichen Daten speichern
  - Keine Informationen über euch z.B. Namen, Alter, Adresse

<!--
Darauf hinweisen, dass jeder Teilnehmer für den Kurs immer den gleichen Rechner bekommt.

Erst nach dem Kurs werden die Rechner wieder platt gemacht.
Projekte können über USB-Sticks mitgenommen werden.
-->

---

# Installation von Visual Studio Code mit PlatformIO

1. Installationsdatei auf https://code.visualstudio.com/ herunterladen
2. VS-Code installieren
3. VS-Code öffnen
4. Im Erweiterungsmanager nach "platformio ide" suchen und installieren
5. Anweisungen nach der Installation befolgen

Nur für Linux: 

- Benutzer muss in der Gruppe dialout sein damit wir den Arduino programmieren können

<!--
## Installation für Zuhause

Auf den Kurs Rechnern ist VS-Code mit PlatformIO bereits installiert.
Die Folie ist der Vollständigkeit halber enthalten.

**Teilnehmer darauf hinweisen, dass VS-Code schon installiert ist und sie es jetzt starten dürfen**
-->

---
layout: image
image: /img/vs-code.png
background-size: 90%
---

<Arrow x1="90" y1="245" x2="80" y2="245" color="orange" width=5 />

<!--
Hier sollte live gezeigt werden, wie man zu dem Zustand aus dem Bild kommt.

1. VS-Code öffnen
2. PlatformIO öffnen (Ameise in der Seitenleiste)
3. Wenn sich PIO Home nicht geöffnet hat über das QUICK ACCESS Menü **Open** anklicken

Wir öffnen jetzt am besten zusammen das Projekt blinkende_led im home Verzeichnis.  
**Auf unseren Kurs Rechnern gibt es im Datei-Auswahl-Dialog in der linken Seite das Bookmark user.**
-->

---
layout: image-left
image: /img/PlatformIO_Menueleiste.png
background-size: 30em
---

# PlatformIO - untere Menüleiste

1. Projekt übersetzen
2. Projekt an Arduino übertragen
3. Seriellen Monitor öffnen
4. Projekt auswählen (wenn mehrer Projekte geöffnet sind)
5. Serielle Schnittstelle (wenn es funktionier auf auto lassen)

<!--
Bisher sollte noch kein Teilnehmer*in seinen Arduino angeschlossen haben!
-->

---
layout: two-cols-header
---

# Projektstruktur

::left::

| | |
|-|-|
| main.cpp in src/ | Unser Programm |
| platformio.ini | Einstellungsdatei für PlatformIO |
| lib Ordner | Speicherort für Bibliotheken |
| include Ordner | Speicherort für Eingebundene Dateien |
| .pio Ordner | Speicherort für gebauten Maschinencode |
| .vscode Ordner | Einstellungen für VS Code |

::right::

```bash
./
├── .pio/
└── .vscode/
    ├── c_cpp_properties.json
    ├── extensions.json
    └── launch.json
├── include/
├── lib/
├── src/
│   └── main.cpp
├── .gitignore
├── platformio.ini

```

<!--
Wir schauen uns die Dateistruktur anhand des geöffneten Projekts an
-->

---

# Grundlagen Programmierung

````md magic-move {at: 1}
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

delay(1000);
pinMode(13, OUTPUT);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

void setup() {
  pinMode(13, OUTPUT);
}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

if(x > 10) {
  digitalWrite(13, HIGH);
} else {
  digitalWrite(13, LOW);
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}
```
```cpp
// Befehle werden mit Strichpunkt beendet!
// Befehle können in runten Klammern Argumente haben
Befehl();
Befehl(Argument1);
Befehl(Argument1, Argument2);

// Hinter Funktionen kommt kein Strichpunkt, sondern geschweifte Klammern
Funktion() {

}

// Bedingungen enden nicht mit Strichpunkt, sondern mit geschweiften Klammern
if(Bedingung) {
  // Was soll passieren?
}

// Schleifen sind fast wie Bedingungen ohne Strichpunkt
while(Bedingung) {
  // Solange ausführen, wie Bedingung wahr ist
}

while(i > 0) {
  digitalWrite(13, HIGH);
  delay(500);
  i = i - 1;
}
```
````

<!--
# Folie ist chronologisch und klickbar!
Bei jedem Klick zeigt sich ein Beispiel und verschwindet mit dem nächsten Klick wieder.
-->

---

# Grundlagen Arduinoprogramm

main.cpp:

```cpp
// Wird beim Programmstart genau 1x ausgeführt
setup() {

}

// Wird immer wieder ausgeführt
loop() {

}
```

<!--
1. Erklären, was die Funktionen besonders macht
2. Teilnehmer*innen nach Anwendungszweck fragen
3. Auflösung:
  - In setup() machen wir initiale "Einstellungen" und setzen den Startpunkt für das Programm fest
  - In loop() steht unsere eigentliche Programmlogik, die wir programmieren
-->

---
layout: statement
---
# Noch Fragen?

---

# Blinkende LED

1. Öffne das Projekt "blinkende_led"
2. Schließ deinen Arduino an
3. Spiele das Programm auf deinen Arduino

## Fragen (5 Minuten)
- Was passiert?
- Wofür brauchst du "pinMode" und was machst du damit?
- Was passiert, wenn du 1000 durch z.B. 100 ersetzt?
- Was macht "digitalWrite" und wie funktioniert das?
- Was ist der Unterschied zwischen HIGH und LOW?

<!--
Uhrzeit bis wann Ergebnisse besprochen werden anschreiben.
-->

---
layout: image-left
image: /img/blinkende_led.png
background-size: 50em
---

# Externe LED

<v-clicks>

- Warum brauchst du einen Widerstand vor der LED?
<v-click>&nbsp&nbsp&nbsp&nbsp=> Damit nicht zu viel Strom durch die LED fließt</v-click>
- Ob der Widerstand bei + oder - eingebaut ist, ist egal
- Auf die Polarität achten!

<br>Schaltung aufbauen und Programm anpassen -> Los Gehts!

</v-clicks>

<!--
**Dass die LED mit PIN 12 verbunden ist ist absicht**
-->

---
---

# Wie weißt du was der Arduino gerade macht?

```cpp
// Wird beim Programmstart genau 1x ausgeführt
setup() {
  Serial.begin(9600);   // Seriellen Monitor starten
}

// Wird immer wieder ausgeführt
loop() {
  Serial.println("Hallo Welt");   // Text auf seriellem Monitor ausgeben
}
```

- Ausgabe vom Arduino über **Seriellen Monitor**

## Aufgabe

1. `monitor_speed = 9600` in platformio.ini ergänzen
2. Seriellen Monitor starten
3. Ausgeben lassen, ob die LED gerade ein oder aus ist

---

# Wir wollen die Zeiten ändern - Aber einfach!

Damit wir die Zeiten nicht überall austauschen müssen gibt es **Variablen**.

Es gibt Variablen mit unterschiedlichen Typen:

|  |  |
| ------------- | --- |
| bool | Wahrheitswert |
| int | Ganzzahl |
| float | Kommazahl |
| double | Kommazahl, aber größer |
| char | Zeichen |
| string | Zeichenkette |

<!--
Teilnehmer*innen müssen sich nicht alle Typen merken.

Wichtig sind für den Anfängerkurs vor allem int und bool, später auch noch float/double.
-->

---
---

# Variablen verwenden

- Variablen gelten nur da, wo ich sie anlege!
  - Wenn ich eine Variable in **setup()** anlegen kann ich sie in **loop()** nicht verwenden
  - Wenn ich eine Variable ganz oben außerhalb von **setup()** und **loop()** anlege kann ich sie überall verwenden

- Variablen anlegen: `Schlüsselwort NameDerVariable = Startwert;`

```cpp
int GanzeZahl = 7;
```

- Variable verwenden: `NameDerVariable = NeuerWert;`
TolleFunktion(GanzeZahl);
```cpp
GanzeZahl = 4;
```

- Variable verwenden: `Funktion(NameDerVariable);`

```cpp
TolleFunktion(GanzeZahl);
TolleFunktion(4);
```

---
layout: statement
---

# Programm umbauen <br> - <br> Variablen verwenden

Alle festen Zahlen durch Variablen ersetzen

---
layout: two-cols-header
---

# Erweiterungen

::left::

### Eigenes Blinkmuster

- Lass deine LEDs in einem eigenen Muster blinken

::right::

### Name in Morse-Code

<div style="display: flex; flex-direction: column; gap: 4px;">
  
  <div style="margin: 0;">Morse-Alphabet:</div>
  <QRCode
    :width="150"
    :height="150"
    type="svg"
    data="https://de.wikipedia.org/wiki/Morsecode#/media/Datei:International_Morse_Code.svg"
    :margin="0"
    :imageOptions="{ margin: 0 }"
    :dotsOptions="{ type: 'extra-rounded', color: 'green' }"
  />

  <div style="margin-top: 8px;">Morse-Dekoder (https://sollozzo2.github.io/smorse):</div>
  <QRCode
    :width="150"
    :height="150"
    type="svg"
    data="https://sollozzo2.github.io/smorse"
    :margin="0"
    :imageOptions="{ margin: 0 }"
    :dotsOptions="{ type: 'extra-rounded', color: 'green' }"
  />

</div>

<style>
.two-cols-header {
  column-gap: 20px; /* Adjust the gap size as needed */
}
</style>

<!--
Darauf hinweisen, dass die Zeitabstände beim Morse-Code NICHT beliebig sind.

Steht auf dem verlinkten Bild ganz oben!

Ein kurzes blinken ist eine UNIT lang
Ein langes blinken ist drei UNITs lang
Abstand zwischen Symbolen ist eine UNIT lang
Abstand zwischen Wörtern ist sieben UNITs lang
-->

---
---

# Challenge - Lauflicht mit mehreren LEDs

- Zusätzliche LEDs einbauen
- Jede LED braucht einen passenden Vorwiderstand
- LEDs sollen nacheinander ein gehen und dann wieder aus

---

# Zusatzaufgabe - Automatischer Blinker

- Lauflicht soll schneller und langsamer werden
- Beginnt bei 200ms
- Endet bei 5s

<!--
# Diese Aufgabe greift auf den nächsten Termin vor!

Lösung soll ohne Schleifen gemacht werden!
-->

---
layout: full
---

# Zusammenfassung

<StickyNote color="amber-light" width="220px" title="Arduino" v-drag="[120, 120, 220, 130]" style="transform: rotate(-3deg)">
  
  - Mikrocontroller mit Ein- und Ausgängen
  - Frei programmierbar
</StickyNote>

<StickyNote color="pink-light" width="240px" title="LEDs" v-drag="[360, 100, 240, 130]" style="transform: rotate(2deg)">

  - LEDs haben einen Plus-Pol (Anode) und einen Minus-Pol (Kathode)
  - LEDs brauchen Vorwiderstände!
</StickyNote>

<StickyNote color="teal-light" width="280px" title="Serieller Monitor" v-drag="[620, 140, 280, 130]" style="transform: rotate(-5deg)">

  - Starten mit `Serial.begin(9600);`
  - Text ausgeben mit `Serial.println("Hallo Welt");`
</StickyNote>

<StickyNote color="green-light" width="240px" title="Aufbau Arduino Programm" v-drag="[200, 320, 240, 130]" style="transform: rotate(4deg)">

  - `setup()` wird nur 1-mal aufgerufen
  - `loop()` läuft in Dauerschleife
</StickyNote>

<StickyNote color="sky-light" width="240px" title="Variablen" v-drag="[500, 340, 240, 130]" style="transform: rotate(-2deg)">

  - Werte können wir in Variablen speichern
  - Es gibt unterschiedliche Typen
</StickyNote>
