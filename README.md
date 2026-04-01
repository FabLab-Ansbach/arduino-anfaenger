# Arduino Angängerkurs

|                 |                                                             |
| ----------------| ----------------------------------------------------------- |
| Zielgruppe      | 12-16 Jahre                                                 |
| Dauer           | 5 Termina a 4 Stunden                                       |
| Ziel            | Vermittlung von Grundlagen in Programmierung und Elektronik |
| Voraussetzungen | **Keine**                                                   |
| Hardware        | Funduino Experimentierkasten                                |
| Software        | VS Code mit PlatformIO                                      |

## Verzeichnisstruktur

Für jeden Termin gibt es ein eigenes Verzeichnis, das jeweils die Präsentation (slides), Schaltpläne bzw. KiCAD/Fritzing Projekte (schaltplan) und Beispiel- bzw. Musterlösungs-Code beinhaltet. Alle weiteren Dokumente die zum Kurs gehören befinden sich im Verzeichnis docs. Dazu zählen z.B. das Code Guideline Sheet oder das vorbereitete Cheatsheet.

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
  - Zusatzaufgabe (Für sehr schnelle Teilnehmer*innen, die auch die Challenge geschafft haben)
  - Challenge (Knifflige Aufgabe, die auch Denken über den Tellerrand hinaus erfordert)
- Lösung der Pflichtaufgabe wird in der Gruppe besprochen, wenn alle fertig sind
- Lösungen der Zusatz-/Challengeaufgaben in Gruppe besprechen, wenn alle auch damit fertig sind - ansonsten nicht!
- Aufgabenstellungen für Zusatz-/Challengeaufgaben auf Karten zum "abholen" bei den Betreuern
  - Dadurch auch Wissenskontrolle und Überprüfung der Lösung möglich
  - Teilnehmer können unabhängig von der aktuellen Slide weiterarbeiten
- Am Ende jeden Termins gibt es einen kurzen Rückblick
  - Was haben wir heute gelernt?
- Am Ende jeden Termins gibt es einen kurzen Rückblick
  - Was haben wir heute gelernt?
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
- Spickzettel zum selbst ausfüllen
  - Befehle und Beschreibungen
  - Nur so viel wie man für die Aufgabe braucht
  - In Eigenverantwortung jeder für sich
- Fertigen Spickzettel für alle am Ende
