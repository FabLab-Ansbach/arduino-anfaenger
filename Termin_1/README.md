# Termin 1 - Die digitale Welt; "Hallo Arduino"

**Kapitel im Heft:** Kapitel 2 (Hardware und Software), Kapitel 4.1 (Eine blinkende LED)

## Theorie

**Referenz:** Kapitel 2.1.1 (Der Mikrocontroller), Kapitel 2.1.2 (Das Breadboard), Kapitel 2.1.3 (LEDs)

- Anmeldung mit Benutzername und Passwort erklären

- Was ist ein Mikrocontroller? Was ist ein Arduino?
  - **Referenz:** Abbildung aus Heft Seite 12 (UNO, NANO, MEGA mit Beschriftung)
- Überblick zum Arduino
  - USB-Anschluss
  - Reset-Button
  - Spannungs-Pins => VCC (+5V), GND
  - Digitale Ein- und Ausgänge
  - Analoge Ein- und Ausgänge
- Überblick zum Breadboard
  - **Referenz:** Heft Seite 12-13
  - Erklärung der Kontakte => Äußere Linie = Spannungsversorung, innere Segmente = immer 5 Kontakte verbunden
- Überblick LEDs
  - Wichtige Informationen: Heft Seite 13
  - Stromrichtung => Langes Bein + (Anode), Kurzes Bein - (Kathode)
  - Vorwiderstand ist immer nötig!
  - Empfohlene Widerstände => Heft Seite 14
- Überblick zur verwendeten Software
  - Überblick VS-Code und PlatformIO
    - Hinweise zur Installation geben!
  - Warum verwenden wir PlatformIO und nicht ArduinoIDE?
    - Arbeiten mit einer "richtigen" Entwicklungsumgebung
    - Einfacher durch Intelli-Sense und Code-Vervollständigung
    - Lizenzthematik von Arduino seit der Übernahme durch Qualcomm
  - Wie öffne ich ein bestehendes Projekt?
  - Wie lege ich ein neues Projekt an?
- Überblick über die Projektstruktur vom PlatformIO
  - platformio.ini
  - src Verzeichnis => main.cpp
- Erklärung setup() und loop()
  - **Referenz:** Kapitel 4.1, Seite 24-25
- Grundlegende Dinge erklären
  - Befehle werden immer mit Strichpunkt beendet
  - Befehel haben Argumente in runden Klammern
  - Bei Schleifen, Bedingungen, Funktionen etc. brauchen wir geschweifte Klammern und keinen Strichpunkt

## Pflichtprojekt

**Referenz:** Heft Kapitel 4.1 (Eine blinkende LED), Seite 24-25

1. Code vorbereitet auf den Rechnern
2. Teilnehmer*innen öffnen Projekt und übertragen es auf den Arduino
3. Fragestellungen:
   - Was passiert, wenn ich 1000 durch 100 ersetze?
   - Was ist der Unterschied zwischen HIGH und LOW?
   - Was macht pinMode?
4. Ergebnisse in der Gruppe sammeln
5. Externe LED hinzufügen
   - Schaltung als Schaltplan vorbereitet
   - Schaltung zusammen besprechen
   - Theorieblock => Vorwiderstand? Warum? => **Referenz:** Heft Seite 13-14
   - Schaltung aufbauen lassen
   - Programm selbstständig anpassen
6. Wie weiß ich was der Arduino gerade macht?
   1. Seriellen Monitor einführen => Wollen wir in Zukunft immer im Programm haben (und benutzen)
   2. Serial.begin(9600) in setup() ergänzen
   3. Serial.println("LED an"); und Serial.println("LED aus"); in loop() ergänzen
   4. ggf. monitor_speed = 9600 in platformio.ini ergänzen

### Erweiterung 1

- Was wenn ich Zeiten ändern will?
- Einführung von Variablen als Konzept
- Teilneher*innen bauen ihren Code selbstständig um
  - Pin-Nummern und Zeiten in Variablen am Anfang
- **Jetzt das Merkblatt mit Code-Regeln austeilen**

### Erweiterung 2

1. Eigenes Blinkmuster
2. Namen mit Morsecode ausgeben

## Challenge - Lauflicht mit mehreren LEDs

- Lauflicht mit mehreren LEDs
- **Ohne Array oder Schleifen**
- Jede LED mit eigenem Vorwiderstand
- Ausblick: Was wäre, wenn man jetzt 20 oder mehr LEDs hätte? Geht das im Programm auch einfacher/eleganter?

## Zusatzaufgabe - Automatischer Blinker

- Lauflicht soll automatisch schneller und wieder langsamer werden
- Beginn bei 200ms und Ende bei z.B. 5s

## Ausblick

Wir können vom Arduino jetzt Sachen ausgeben lassen, aber wie können wir den Arduino steuern?
