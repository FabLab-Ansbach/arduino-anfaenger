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

---
layout: image
image: ./img/fablab_logo.svg
background-size: 30em
---
# Das FabLab

---
layout: image
image: ./img/ANsWERK_Logo.png
background-size: 30em
---
# Das ANsWERK

---
layout: image-left
image: ./img/Arduino_Uno.webp
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

---
layout: image-right
image: ./img/Breadboard.png
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

---
layout: image-left
image: ./img/led_aufbau.svg
background-size: 15em
---

# Die LED

## (Heft S. 13)

- Haben eine feste Polarität!
- + (Anode) = längeres Beinchen
- - (Kathode) = kürzeres Beinchen oder beim "Kelch"
- Merkhilfe: Mit dem längeren Beinchen kann ich leichter ein + machen als mit dem kürzeren

---
layout: image-right
image: ./img/led_aufbau.svg
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

---
layout: default

# Überblick über VS-Code mit PlatformIO
---
# Anmeldung am Laptop

- Benutzername: **user** | Passwort: **fablab**
- Keine persönlichen Daten speichern

---

# Installation von Visual Studio Code mit PlatformIO

1. Installationsdatei auf https://code.visualstudio.com/ herunterladen
2. VS-Code installieren
3. VS-Code öffnen
4. Im Erweiterungsmanager nach "platformio ide" suchen und installieren
5. Anweisungen nach der Installation befolgen

Nur für Linux: 

- Benutzer muss in der Gruppe dialout sein damit wir den Arduino programmieren können

---
layout: image
image: ./img/vs-code.png
background-size: 90%
---

<Arrow x1="90" y1="245" x2="80" y2="245" color="orange" width=5 />

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

---
---

# Grundlagen Programmierung

```cpp
// Befehle werden mit Strichpunkt beendet!
Befehl();

// Befehle können in runten Klammern Argumente haben
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

---
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

---
---

# Blinkende LED

1. Öffnet das Projekt "blinkende_led"
2. Schließt euren Arduino an
3. Spielt das Programm auf euren Arduino

## Fragen
- Was passiert?
- Wofür brauchen wir "pinMode", was machen wir damit?
- Was passiert, wenn wir 1000 durch z.B. 100 ersetzen?
- Was machet digitalWrite und wie funktioniert das?
  
---
layout: image-left
image: ./img/blinkende_led.png
background-size: 50em
---

# Externe LED

<v-clicks>

- Warum brauchen wir einen Widerstand vor der LED?
<v-click>&nbsp&nbsp&nbsp&nbsp=> Damit nicht zu viel Strom durch die LED fließt</v-click>
- Ob der Widerstand bei + oder - eingebaut ist, ist egal
- Auf die Polarität achten!

<br>Schaltung aufbauen und Programm anpassen -> Los Gehts!

</v-clicks>

---
---

# Wie weiß ich was der Arduino gerade macht?

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
---

# Wir wollen die Zeiten ändern - Aber einfach!

Damit wir die Zeiten nicht überall austauschen müssen gibt es **Variablen**.

Es gibt Variablen mit unterschiedlichen Typen:

|  |  |
| ------------- | --- |
| bool | Wahrheitswert |
| int | Ganzzahl |
| float | Kommazahl |
| double | Kommazahl |
| char | Zeichen |
| string | Zeichenkette |

---
---

# Variablen verwenden

- Variablen gelten nur da, wo ich sie anlege!
  - Wenn ich eine Variable in **setup()** anlgege kann ich sie in **loop()** nicht verwenden
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

- Lasst eure LEDs in einem eigenen Muster blinken

::right::

### Name in Morse-Code

Morse Alphabet:
<QRCode
    :width="200"
    :height="200"
    type="svg"
    data="https://de.wikipedia.org/wiki/Morsecode#/media/Datei:International_Morse_Code.svg"
    :margin="10"
    :imageOptions="{ margin: 10 }"
    :dotsOptions="{ type: 'extra-rounded', color: 'green' }"
/>


<style>
.two-cols-header {
  column-gap: 20px; /* Adjust the gap size as needed */
}
</style>

---
---

# Challenge - Lauflicht mit mehreren LEDs

- Zusätzliche LEDs einbauen
- Jede LED braucht einen passenden Vorwiderstand
- LEDs sollen nacheinander ein gehen und dann wieder aus

---
---

# Zusatzaufgabe - Automatischer Blinker

- Lauflicht soll schneller und langsamer werden
- Beginnt bei 200ms
- Endet bei 5s

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