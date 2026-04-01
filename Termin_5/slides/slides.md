---
# try also 'default' to start simple
theme: neversink
color: green-light
title: Arduino Anfängerkurs - Termin 5
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
layout: statement
---

# Rückblick - ClassQuiz

---
---

# Heute

- Eigenes Projekt planen und aufbauen (ca. 2 1/2 Stunden)
- Projektergebnisse vorstellen (ca 1 Stunde)

---
layout: statement
---

# Das Abschlussprojekt

Heute baust du etwas, das **du dir ausgedacht hast**

---
---

# Das Projektblatt

Bevor ihr anfangt, füllt ihr ein **Projektblatt** aus:

<v-clicks>

- Name des Projekts
- Was soll das Projekt können? *(1–2 Sätze)*
- Welche Bauteile brauche ich?
- Skizze der Schaltung
- Wie fange ich an? *(Erster Schritt)*
- Erwartete Schwierigkeiten

</v-clicks>

<v-click>

**Ihr habt 20 Minuten – dann schauen wir gemeinsam drüber!**

</v-click>

---
layout: two-cols-header
---

# Projektideen – Einfach

::left::

### Alarmanlage

- Taster als Sensor
- Buzzer als Alarm
- LED: rot = scharf, grün = aus
- Display zeigt Status

::right::

### Stimmungslampe

- Potentiometer wählt Farbe
- Zweites Poti stellt Helligkeit ein
- Taster wechselt Effekte

<style>
.two-cols-header {
  column-gap: 20px;
}
</style>

---
layout: two-cols-header
---

# Projektideen – Mittel

::left::

### Thermometer mit LCD

- TMP36 Sensor *(Material 22)*
- Anschluss selbst im Heft nachschlagen!
- Temperatur auf Display
- LED-Ampel: Grün / Gelb / Rot

::right::

### Reaktionsspiel

- 3–5 LEDs leuchten zufällig auf
- Passenden Taster drücken
- Falscher Taster → Game Over
- LCD zeigt Punktestand

<style>
.two-cols-header {
  column-gap: 20px;
}
</style>

---
---

# Projektidee – Schwer: Passwortschloss

- 4 Taster als Code-Eingabe
- Richtige Reihenfolge → grüne LED + Erfolgsmelodie
- Falsche Eingabe → rote LED + Fehler-Ton
- Display zeigt „Gesperrt" / „Offen"

<v-click>

> **Hinweis:** Im Kurs lösen wir das mit `if/else` – die elegantere Lösung mit Arrays kommt im Fortgeschrittenenkurs!

</v-click>

---
layout: statement
---

# Du füllst dein Projektblatt aus!

ca. 20-30 Minuten

---
layout: statement
---

# Los gehts! ⚡
Baue deine Schaltung auf und programmiere deinen Arduino

---
---

# Projektpräsentation

Jede*r stellt sein Projekt vor **(3–5 Minuten)**:

<v-clicks>

- Was macht mein Projekt? *(Funktion in einem Satz)*
- Wie funktioniert es? *(Ein Bauteil oder Konzept erklären)*
- Was war schwierig – und was habe ich gelernt?
- Was will ich als nächstes dazu bauen?

</v-clicks>

---
---

# Zusatzaufgabe - Entwickler-Logbuch

Für alle, die früh fertig sind – schreibe eine Dokumentation für dein Projekt:

<v-clicks>

1. Projektname und Beschreibung
2. Bauteilliste – Welche Bauteile? Welche Pins?
3. Schaltplan-Skizze *(handgezeichnet ist OK)*
4. Erklärung des Codes – `setup()`, `loop()`, eigene Funktionen
5. Bekannte Probleme / Was noch nicht funktioniert
6. Was ich als nächstes bauen würde

</v-clicks>

---
layout: statement
---1

# Rückblick auf eure Wunschliste von Tag 1

Was haben wir erreicht? Was ist noch offen?

---
---

# Was kommt als nächstes?

<v-clicks>

- **Fortgeschrittenenkurs:** Arrays, `millis()`, eigene Bibliotheken, komplexere Projekte
- **KidsLab:** Weitere Kurse und Projekte im FabLab
- Eure Projekte könnt ihr jederzeit hier weiter ausbauen!

</v-clicks>

---
layout: full
---

# Was ihr gelernt habt

<StickyNote color="amber-light" width="200px" title="Hardware" v-drag="[80, 120, 200, 150]" style="transform: rotate(-3deg)">

  - Arduino, Breadboard
  - LEDs, Taster, Sensoren
  - Buzzer, LCD-Display
</StickyNote>

<StickyNote color="pink-light" width="220px" title="Digitale Signale" v-drag="[310, 90, 220, 150]" style="transform: rotate(2deg)">

  - `digitalRead()` / `digitalWrite()`
  - Pull-Up Widerstand
  - if / else
</StickyNote>

<StickyNote color="teal-light" width="220px" title="Analoge Signale" v-drag="[560, 110, 220, 150]" style="transform: rotate(-4deg)">

  - `analogRead()` / `analogWrite()`
  - PWM, map()
  - Potentiometer, LDR
</StickyNote>

<StickyNote color="green-light" width="220px" title="Programmierung" v-drag="[160, 310, 220, 150]" style="transform: rotate(3deg)">

  - Variablen & Typen
  - for-Schleifen
  - Eigene Funktionen
</StickyNote>

<StickyNote color="sky-light" width="220px" title="Kommunikation" v-drag="[420, 320, 220, 150]" style="transform: rotate(-2deg)">

  - Serieller Monitor
  - I²C Protokoll
  - Libraries einbinden
</StickyNote>