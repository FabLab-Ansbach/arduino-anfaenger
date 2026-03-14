# Termin 2 - Eingaben & Entscheidungen

## Rückblick

- **Aktiver Rückblick:** Code mit 3 Fehlern auf Beamer präsentieren
- Teilnehmer*innen finden und besprechen die Fehler
- Beispielfehler:
  - `pinmode` statt `pinMode` (Groß-/Kleinschreibung)
  - Fehlende Klammer `}`
  - `digitalwrite` statt `digitalWrite`

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

## Erweiterung 2 - Ampelschaltung mit Taster

- Ampelschaltung mit Rot, Gelb und Grüner LED
- Unterschiedliche Zeiten wie bei echter Ampel
- Zeiten in Variablen eingestellt

## Challenge - Reaktionsspiel mit LED und Taster

**Ziel:** Die LED leuchtet nach einer zufälligen Wartezeit auf. Spieler*in drückt so schnell wie möglich den Taster. Die Reaktionszeit wird über drei LEDs angezeigt (grün = schnell, gelb = mittel, rot = langsam).

**Wichtig:** Es wird **kein** `millis()` gebraucht! Die Zeitspanne wird durch aufeinanderfolgende `delay()`-Aufrufe gemessen.

**Vereinfachte Logik:**

- LED leuchtet auf
- Warte in 50ms-Schritten und zähle mit, bis Taster gedrückt wird
- Je nach Anzahl Schritte: grüne, gelbe oder rote LED leuchten lassen
- Zusätzlicher Taster zum Neustarten

**Hinweis:** Wenn der Taster nach weniger als 500ms (ca. 10 Schritte) gedrückt wird → grüne LED, 500-1000ms → gelbe LED, über 1000ms → rote LED

## Zusatzaufgabe - Entprellter Taster

**Für sehr schnelle Teilnehmer*innen.**

Wer die Toggle-Funktion gebaut hat, hat vermutlich bemerkt: Manchmal schaltet die LED zweimal. Das ist das **Prellen** des Tasters.

**Aufgabe:** Baue eine Software-Entprellung:

- Wenn Taster gedrückt: Warte 50ms
- Prüfe nochmals: Ist er immer noch gedrückt?
- Nur dann gilt es als echter Tastendruck

**Cliffhanger:** "Was wäre, wenn du `delay(50)` nicht verwenden kannst, weil der Arduino in dieser Zeit noch andere Dinge tun muss? Das lösen wir im Fortgeschrittenenkurs."
