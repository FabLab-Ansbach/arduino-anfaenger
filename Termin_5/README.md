# Termin 5 - Eigenes Projekt

## Rückblick

- **Kahoot-Quiz:** Max. 10 Fragen, max. 15 Minuten
- Fragen decken alle Termine ab

## Abschlussprojekt - Projektblatt & Planung

Jeder Teilnehmer*in soll im letzten Termin ein eigenes Projekt aufbauen und programmieren.
Am Ende des Termins soll jeder eine funktionierende Schaltung haben und ein Programm dafür geschrieben haben.

- **Jeder bekommt ein "Projektblatt" mit:**
  - Name des Projekts
  - Was soll das Projekt können (1-2 Sätze)
  - Welche Bauteile brauche ich
  - Skizze der Schaltung
  - Wie fange ich an (Erster Schritt)
  - Erwartete Schwierigkeiten
- **20 Minuten Zeit** um das Projektblatt auszufüllen
- Nach dieser Zeit schauen die Kursleiter die Ideen an und geben das GO
- **Wichtig:** Realistische Erwartungen setzen, ggf. Projekt vereinfachen

## Projektpräsentation (letzten 45 Minuten)

Am Ende soll jeder Teilnehmer*in sein Projekt der Gruppe vorstellen (3-5 Minuten pro Person):

- Was macht mein Projekt? (Funktion in einem Satz)
- Wie funktioniert es? (Ein Bauteil oder Konzept erklären)
- Was war schwierig und was habe ich gelernt?
- Was will ich als nächstes dazu bauen?

**Tipp für Kursleiter:** Lobend hervorheben, was jede*r gelernt hat – unabhängig von der Komplexität des Projekts.

## Projektideen

### Alarmanlage (Einfach)

**Buchbezug:** Kombination aus Taster (Material 25/26), Buzzer (Material 27), LED, LCD (Material 28)

Schwierigkeit: Einfach

- Magnetkontakt oder Taster als Sensor
- Buzzer als Alarm
- LED als Anzeige (rot = scharf, grün = aus)
- Display für Statusanzeige („System scharf" / „Alarm!")
- Taster zum Ein- und Ausschalten des Alarms

**Ablauf:**

1. System ist aus (grüne LED)
2. Taster 1: System scharf schalten (rote LED)
3. Wenn Tür-Sensor (Taster 2) ausgelöst: Buzzer + LCD zeigt „ALARM!"
4. Taster 1 erneut: System wieder ausschalten

### Stimmungslampe (Einfach)

**Buchbezug:** Potentiometer (Material 24), RGB-LED (Material 8) oder mehrere LEDs, Taster (Material 25/26)

Schwierigkeit: Einfach

- Potentiometer wählt eine Farbe aus (bei RGB-LED)
- zweites Potentiometer stellt die Helligkeit ein
- Taster zum Wechseln zwischen Effekten (z.B. Dauer-Ein oder Blinken)

**Variante ohne RGB-LED:** Verschiedenfarbige LEDs, Potentiometer wählt aus, welche leuchtet

### Thermometer mit LCD und LED (Mittel)

**Buchbezug:** Temperatursensor (Material 22 - TMP36), LCD (Material 28), LEDs

Schwierigkeit: Mittel

- Temperatur mit Sensor messen (Anschluss selbst im Heft nachschlagen)
- **Anschluss selbst im Funduino-Heft nachschlagen** (Material 22)
- Anzeige der Temperatur auf Display
- LED-Ampel mit Grenzwerten
  - Grün: unter 22°C
  - Gelb: 22-25°C
  - Rot: über 25°C

**Hinweis:** TMP36 auslesen ist analog (`analogRead()`), Umrechnung in °C erforderlich

### Reaktionsspiel mit mehreren LEDs (Mittel)

**Buchbezug:** Kombination mehrerer LEDs, Taster, `random()`

Schwierigkeit: Mittel

- Mehrere LEDs (3-5) und gleich viele Taster
- LEDs leuchten zufällig auf
- Passend zur leuchtenden LED muss der passende Taster gedrückt werden
- Wenn der falsche Taster gedrückt wird: Buzzer-Fehler-Ton, Spiel vorbei
- LCD zeigt Punktestand

**Ablauf:**

1. Zufällige LED leuchtet auf
2. Spieler*in drückt entsprechenden Taster
3. Richtig: Punkt + nächste Runde
4. Falsch: Game Over + Highscore anzeigen

### Passwortschloss (Schwer)

**Buchbezug:** Taster (Material 25/26), LCD (Material 28), LEDs, Buzzer

Schwierigkeit: Schwer

- 4 Taster als Code-Eingabe
- Codeabfrage z.B. mit verschachteltem if/else => Bessere Lösung in Fortgeschrittenen Kurs
  - **Hinweis:** Bessere Lösung (Arrays) im Fortgeschrittenenkurs
- Bei richtiger Reihenfolge: Grüne LED blinkt, Buzzer spielt Erfolgsmelodie
- Bei falscher Eingabe: Rote LED, Fehler-Ton
- Zustand des Schlosses wird auf Display angezeigt („Gesperrt" / „Offen")

**Vereinfachte Version (im Kurs machbar):** Code mit verschachtelten `if/else` prüfen
**Vollständige Version:** Hinweis, dass elegantere Lösung mit Arrays im Fortgeschrittenenkurs kommt

### Zusatzaufgabe - Entwickler-Logbuch

**Für Teilnehmer*innen, die ihr Projekt früh fertiggestellt haben.**

Schreibe eine vollständige Entwicklerdokumentation für dein Abschlussprojekt. Sie soll so geschrieben sein, dass jemand, der deinen Code noch nie gesehen hat, das Projekt nachbauen und verstehen kann.

**Deine Dokumentation enthält:**

1. Projektname und Beschreibung (ein Satz)
2. Bauteilliste – Welche Bauteile? Welche Pins?
3. Schaltplan-Skizze (handgezeichnet ist OK)
4. Erklärung des Codes
   - Was macht `setup()`?
   - Was passiert in jedem Durchlauf von `loop()`?
   - Was macht jede Funktion, die du geschrieben hast?
5. Bekannte Probleme / Was noch nicht funktioniert
6. Was ich als nächstes bauen würde

**Warum ist das wertvoll?**

- Wer etwas erklären kann, hat es wirklich verstanden
- Die Dokumentation kann bei der Präsentation als Spickzettel dienen
- Für den Fortgeschrittenenkurs: Projekt kann sofort wieder aufgegriffen werden
