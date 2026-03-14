# Arduino Angängerkurs

|                 |                                                             |
| ----------------| ----------------------------------------------------------- |
| Zielgruppe      | 12-16 Jahre                                                 |
| Dauer           | 5 Termina a 4 Stunden                                       |
| Ziel            | Vermittlung von Grundlagen in Programmierung und Elektronik |
| Voraussetzungen | **Keine**                                                   |
| Hardware        | Funduino Experimentierkasten                                |
| Software        | VS Code mit PlatformIO                                      |

## Allgemeine Informationen

Der Anfängerkurs soll Grundlagen im Umgang mit Elektronik vermitteln. Gleichzeitig sollen die Teilnehmer*innen einen Einstieg und einen Überblick in die Programmierung von Mikrocontrollern bekommen.

### Grundlegender Aufbau

- Technische Grundlagen legen
- Denkweise eines Entwicklers vermitteln
- Von Anfang an sauber strukturierten Code schreiben
- Hardware soll verstanden werden und nicht nur "zusammengesteckt" werden

### Genaue Zielvorgaben

Am Ende des Kurses sollte jeder Teilnehmer*in:

- Den grundlegenen Aufbau eines Mikrocontrollers und dessen Pins (am Beispiel Arduino) kennen und verstehen
- Schaltungen auf einem Breadboard aufbauen und einen einfachen Schlatplan (Fritzing) lesen können
- Grundlegende Bauteile kennen und anwenden können
  - LED
  - Widerstand
  - Taster
  - Potentiometer
- Grundlegende Struktur eines Arduino-Programms kennen und verstehen (setup und loop)
- Variablen deklarieren und nutzen können
- Bedingte Anweisungen mit if/else einsetzen können
- Schleifen verwenden können

### Didaktisches Konzept

#### Methodik

- ca. 80% Praxisanteil ("learning by doing")
- Jeder Termin sollte mit einem funktionierenden Projekt oder Beispiel enden
- Jeder Termin hat klare Ziele
  - Pflichtziel (Alle Teilnehmer*innen erreichen dieses Ziel) => Wird für den nächsten Termin vorausgesetzt
  - Erweiterung (Für Teilnehmer*innen die früh fertig sind) => Vertieft das aktuelle Thema ohne neuen Lerninhalt
  - Challenge (Knifflige Aufgabe, die auch Denken über den Tellerrand hinaus erfordert)
  - Zusatzaufgabe (Für sehr schnelle Teilnehmer*innen, die auch die Challenge geschafft haben)
- Am Ende jeden Termins gibt es eine kurze Feedback-Runde
  - Was haben wir heute gelernt?
- Am Ende jeden Termins soll jeder Teilnehmer*in auf einen Zettel schreiben:
  - Eine Sache, die ich gelernt habe
  - Eine Frage, die ich noch habe

#### Herangehensweise der Wissensvermittlung

- Erfolgserlebnisse als Antrieb
- Kein Abtippen von ganzem Code, sondern selbst ausprobieren
- Fragen statt Vormachen und Abtippen:
  - Was ist ein Eingang?
  - Was ist ein Ausgang?
  - Welche Informationen brauche ich zur Umsetzung?
  - Was soll passieren, wenn... ?
- Fehler mit den Teilnehmer*innen gemeinsam analysieren, statt den Fehler stumpf zu korrigieren

### Sonstiges

- Handout mit Code-Regeln, die jeder Teilnehmer*in befolgen soll
  - Jeder Pin bekommt einen Namen => Es werden keine Pins direkt mit Nummern verwendet
  - Jede Variable hat einen sprechenden Namen => Nicht x sondern z.B. wartezeit
  - Jeder Block hat einen aussagekräftigen Kommentar
  - Jedes setup() beginnt mit Serial.begin(9600)
