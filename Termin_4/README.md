# Termin 4 - Ausgaben und Kommunikation

**Referenz:** I²C LCD S. 64 (Kapitel 4.16, Material Nr. 28), Libraries S. 19 (Kapitel 2.2.4)

## Rückblick

- **Daumen-Abstimmungs-Quiz:** Kursleiter zeigt Bauteile auf Beamer
- Alle halten gleichzeitig Daumen hoch (analog) oder Daumen runter (digital)
- Beispiele: LED → Digital, Potentiometer → Analog, Taster → Digital, LDR → Analog

## Theorie Teil 1: Buzzer

**Referenz:** Material Nr. 27 (Piezospeaker)

- Wie funktioniert ein Buzzer
  - Membran schwingt durch elektrische Impulse
  - **Passiver Buzzer:** Braucht Wechselspannung mit bestimmter Frequenz
- `tone()` und `noTone()`
  - `tone(pin, frequenz)` – Erzeugt Ton mit gegebener Frequenz
  - `tone(pin, frequenz, dauer)` – Spielt Ton für bestimmte Zeit
  - `noTone(pin)` – Stoppt den Ton
- Notenwerte als Frequenzen (C4 = 262 Hz, D4 = 294 Hz, E4 = 330 Hz, F4 = 349 Hz, G4 = 392 Hz)
- Einbindung von Libraries mit lib_deps in platform.io
  - **Referenz:** Heft S. 19, Kapitel 2.2.4 (Bibliotheken hinzufügen)

## Pflichtprojekt - Melodie

**Ziel:** Eine einfache Melodie spielen (z.B. erste Töne von "Hänschen klein")

**Schaltung:**

- Buzzer (Piezospeaker): Positiver Pin → Pin 8, Negativer Pin → GND

1. Funktion zum abspielen von Noten vorbereitet
2. Definition von Noten mit Frequenzen (C4, D4, E4, F4, G4)
3. Anfang von Hänschen klein abspielen (G-E-E-F-D-D)

**Experimentieraufgaben:**

- Kannst du die nächsten Töne selbst ergänzen?
- Was passiert, wenn du die Dauern veränderst?

## Pflichtprojekt - Text auf LCD

**Referenz:** Heft S. 64, Kapitel 4.16, Material Nr. 28

**Hinweis für Kursleiter:** *(Die Reihenfolge ist bewusst: Kinder sehen zuerst, dass etwas funktioniert – dann erklärt der Theorieteil warum. Die Fragen "Wie weiß der Arduino die Adresse?" und "Was ist dieser Bus?" entstehen von selbst.)*

1. **Jeder baut die Schaltung mit LCD auf**
   - VCC → 5V, GND → GND, SDA → A4, SCL → A5

2. **Jeder überträgt das I²C-Scanner-Projekt** (fertiges Projekt bereitstellen)
   - Scannt nach I²C-Geräten und gibt gefundene Adressen aus

3. **I2C-Adresse des Displays wird auf Seriellem Monitor ausgegeben**
   - Jede*r notiert seine Adresse (0x27 oder 0x3F)

4. **Theorieteil:**
   - Was ist I2C?
     - Inter-Integrated Circuit – Kommunikationsprotokoll
     - Zwei Drähte (SDA, SCL) verbinden mehrere Geräte
     - Jedes Gerät hat eine Adresse
   - Warum brauchen wir die Ausgabe vom Seriellen Monitor?
     - Displays haben unterschiedliche Adressen (0x27 oder 0x3F)
   - Welche Befehle brauchen wir um Text zu schreiben?
     - `lcd.init()`, `lcd.backlight()`, `lcd.setCursor(spalte, zeile)`, `lcd.print("Text")`

5. **Jeder Teilnehmer*in schreibt seinen Namen auf das Display**
   - Code-Vorlage mit der richtigen I²C-Adresse

## Erweiterung 1 - Stoppuhr

**Wahl:** Option für Teilnehmer*innen, die früh fertig sind

- Taster startet und stoppt den Timer
- Anzeige der Zeit auf Display im Format `MM:SS`
- Verwendet `millis()` für nicht-blockierende Zeitmessung

## Erweiterung 2 - Eieruhr

**Wahl:** Alternative zur Stoppuhr (komplexer)

- Zeit mit zwei Tastern einstellen (Minuten hoch/runter)
- Zeit mit Taster starten
- Zeit läuft runter auf Display
- Melodie wenn Zeit abgelaufen ist

**Hinweis:** Deutlich komplexer, kombiniert mehrere Konzepte

## Challenge - Mini Klavier

**Ziel:** Mehrere Taster, jeder spielt eine andere Note. Der gespielte Ton wird auf dem Display angezeigt.

**Schaltung:**

- 5 Taster an Pins 2-6 (jeweils mit GND)
- Buzzer an Pin 8
- LCD wie gehabt

**Lernziel:** Arrays in der Praxis, `for`-Schleife zum Abfragen mehrerer Taster

- Mehrere Taster (5 Stück empfohlen)
- Jeder Taster spielt einen anderen Ton ab (C, D, E, F, G)
- Abgespielter Ton wird auf Display angezeigt („Note: C")

## Zusatzaufgabe - Laufschrift auf LCD

**Für sehr schnelle Teilnehmer*innen.**

Schreibe eine Funktion `laufschrift(String text, int zeile, int wartezeit)`, die einen Text von rechts nach links über das Display laufen lässt.

**Lernziel:** Algorithmisches Denken, String-Manipulation, parametrische Funktionen

**Cliffhanger:** "Was wäre, wenn der Text scrollen und gleichzeitig ein Taster abgefragt werden soll? Mit `delay()` geht das nicht sauber – das ist die große Aufgabe des Fortgeschrittenenkurses."
