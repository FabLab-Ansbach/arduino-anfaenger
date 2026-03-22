# Termin 2 - Eingaben & Entscheidungen

## Rückblick

- **Aktiver Rückblick:** Code mit 3 Fehlern auf Beamer präsentieren
- Teilnehmer*innen finden und besprechen die Fehler
- Beispielfehler:
  - `pinmode` statt `pinMode` (Groß-/Kleinschreibung)
  - Fehlende Klammer `}`
  - `digitalwrite` statt `digitalWrite`
  - Fehlernder Strichpunkt

## Theorie

**Referenz:** Heft Seite 7-8 (Taster Nr. 25, 26)

- Digitale Signale einlesen
  - Ein Signal kann nur zwei Zustände haben: HIGH oder LOW
  - HIGH = 5V, LOW = 0V (GND)
- pinMode(), digitalRead() und digitalWrite()
  - `pinMode(pin, INPUT)` oder `pinMode(pin, INPUT_PULLUP)`
  - `digitalWrite(pin, HIGH/LOW)` – kennen wir
  - `digitalRead(pin)` – **neu**: Liefert HIGH oder LOW zurück
- Interner Pull-Up Widerstand
  - Was ist das? Warum brauchen wir ihn?
  - Schaltung mit `INPUT_PULLUP`: Taster zwischen Pin und GND
  - **Wichtig:** Bei `INPUT_PULLUP` ist gedrückt = LOW!
- Bedingungen mit if/else
  - Syntax:

    ```cpp
    if (Bedingung) {
      // Code wenn wahr
    } else {
      // Code wenn falsch
    }
    ```

- Vergleichsoperatoren
  - `==` (gleich), `!=` (ungleich), `>`, `<`, `>=`, `<=`
  - **Häufiger Fehler:** `=` (Zuweisung) vs. `==` (Vergleich)

## Pflichtprojekt - LED mit Taster steuern

**Hinweis `platformio.ini`:** Bereits mit `monitor_speed = 9600` ergänzt (aus Termin 1)

**Ziel:** Solange der Taster gedrückt ist, leuchtet die LED.

**Schaltung:**

- Taster zwischen Pin 2 und GND
- LED + 220Ω Widerstand an Pin 9 und GND

**Vorgehen:**

1. Schaltung gemeinsam aufbauen
2. Code-Gerüst vorgeben mit `TODO` für die `if/else`-Logik
3. Teilnehmer*innen ergänzen die Logik selbstständig
4. **Gemeinsam besprechen:** Warum ist gedrückt = LOW und nicht HIGH?
5. Anzeige des Taster-Status über den Seriellen Monitor

## Erweiterung 1 - Toggle-Funktion

**Ziel:** Bei jedem Tastendruck wechselt die LED ihren Zustand (an → aus → an → aus)

**Hinweis:** Braucht eine Boolean-Variable als Zustandsspeicher und evtl. Entprellung

## Erweiterung 2 - Entprellter Taster

Wer die Toggle-Funktion gebaut hat, hat vermutlich bemerkt: Manchmal schaltet die LED zweimal. Das ist das **Prellen** des Tasters.

**Aufgabe:** Baue eine Software-Entprellung:

- Wenn Taster gedrückt: Warte 50ms
- Prüfe nochmals: Ist er immer noch gedrückt?
- Nur dann gilt es als echter Tastendruck

**Cliffhanger:** "Was wäre, wenn du `delay(50)` nicht verwenden kannst, weil der Arduino in dieser Zeit noch andere Dinge tun muss? Das lösen wir im Fortgeschrittenenkurs."

## Zusatzaufgabe - Ampelschaltung mit Taster

**Für sehr schnelle Teilnehmer*innen.**

- Ampelschaltung mit Rot, Gelb und Grüner LED
- Unterschiedliche Zeiten wie bei echter Ampel
- Zeiten in Variablen eingestellt

## Challenge - Türklingel mit Bestätigung

**Ziel:** Wir simulieren eine Türklingel mit Tastern und LEDs

- Wird der erste Taster (Klingel) gedrückt, blinkt eine rote LED langsam
- Wird der zweite Taster (Türöffner) gedrückt, geht die rote LED aus und eine grüne LED blinkt kurz
- Wird der zweite Taster innerhalb von 5 Sekunden nicht gedrückt blinkt die rote LED schneller

**Hinweise:**

- Wir brauchen Zustandsvariablen (lernen wir eigentlich erst im Fortgeschrittenenkurs; Hier bewusst als Challenge mit drin zum Knobeln)
- Zeitmessung einfach mit Zähler => Solange gewartet werden soll alle delays im Programm zum Zähler dazu addieren
- Umschaltung des Blinktakts über Bedingung
