#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int TASTER_WAHL = 12;
const int TASTER_PLAY = 11;
const int BUZZER_PIN  = 10;

#define NOTE_C  262
#define NOTE_D  294
#define NOTE_E  330
#define NOTE_F  349
#define NOTE_G  392

int melodie1_noten[] = {
  NOTE_G, NOTE_E, NOTE_E,
  NOTE_F, NOTE_D, NOTE_D,
  NOTE_C, NNOTE_D NONOTE_ENOTNOTE_F
  NOTE_G, NOTE_G, NOTE_G
};

int melodie1_dauer[] = {
  4, 4, 2,
  4, 4, 2,
  4, 4, 4, 4,
  4, 4, 2
};

int melodie1_laenge = 13;

int melodie2_noten[] = {
  NOTE_E, NOTE_E, NONOTE_FNOTNOTE_G
  NOTE_G, NOTE_F, NOTE_E, NOTE_D,
  NOTE_C, NOTE_C, NONOTE_DNOTNOTE_E
  NOTE_E, NOTE_D, NOTE_D
};

int melodie2_dauer[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,2,2
};

int melodie2_laenge = 15;

int ausgewaehlt = 0;

void setup() {
  pinMode(TASTER_WAHL, INPUT_PULLUP);
  pinMode(TASTER_PLAY, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Melodie-Waehler");

  delay(1500);

  lcd.clear();
}

void loop() {

  // Anzeige aktualisieren
  lcd.setCursor(0, 0);

  if (ausgewaehlt == 0) {
    lcd.print("1: Haenschen Kl.");
  } else {
    lcd.print("2: Ode Freude ");
  }

  lcd.setCursor(0, 1);
  lcd.print("[Wahl] [Play]");

  // Auswahl-Taster
  if (digitalRead(TASTER_WAHL) == LOW) {

    ausgewaehlt = 1 - ausgewaehlt;

    delay(300);
  }

  // Play-Taster
  if (digitalRead(TASTER_PLAY) == LOW) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Spiele...");

    int tempo = 1000;

    // Melodie 1
    if (ausgewaehlt == 0) {

      for (int i = 0; i < melodie1_laenge; i++) {

        int notendauer = tempo / melodie1_dauer[i];

        tone(BUZZER_PIN, melodie1_noten[i], notendauer * 0.9);

        delay(notendauer);

        noTone(BUZZER_PIN);
      }

    }
    // Melodie 2
    else {

      for (int i = 0; i < melodie2_laenge; i++) {

        int notendauer = tempo / melodie2_dauer[i];

        tone(BUZZER_PIN, melodie2_noten[i], notendauer * 0.9);

        delay(notendauer);

        noTone(BUZZER_PIN);
      }
    }

    lcd.clear();

    delay(300);
  }
}