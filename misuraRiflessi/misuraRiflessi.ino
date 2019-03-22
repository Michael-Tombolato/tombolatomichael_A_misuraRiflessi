#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

int button = 13;
int led = 12;
int buzzer = 11;
int rs = 0;
int e = 1;
int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;
int stato;
int tRandomLed;
int tRandomSuono;
int tempoLed;
int tempoSuono;
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  stato = LOW;
  lcd.setCursor(0,0);
  lcd.print("Clicca");
  while (stato == LOW)
  {
    if (digitalRead(button) == HIGH)
    {
      stato = HIGH;
    }
  }
  lcd.clear();
  stato = LOW;
  tRandomLed = random(1000, 4000);
  delay(tRandomLed);
  digitalWrite(led, HIGH);
  tempoLed = millis();
  while (stato == LOW)
  {
    stato = digitalRead(button);
    if (stato == HIGH)
    {
      digitalWrite(led, LOW);
      tempoLed = millis() - tempoLed;
      lcd.setCursor(0,0);
      lcd.print(tempoLed);
      if (tempoLed > 500)
      {
        lcd.setCursor(13,0);
        lcd.print("Bad");
      }
      else
      {
        lcd.setCursor(12,0);
        lcd.print("Well");
      }
    }
  }
  stato = LOW;
  tRandomSuono = random(1000, 4000);
  delay(tRandomSuono);
  digitalWrite(buzzer, HIGH);
  tempoSuono = millis();
  while (stato == LOW)
  {
    stato = digitalRead(button);
    if (stato == HIGH)
    {
      digitalWrite(buzzer, LOW);
      tempoSuono = millis() - tempoSuono;
      lcd.setCursor(0, 1);
      lcd.print(tempoSuono);
      if (tempoSuono > 500)
      {
        lcd.setCursor(13,1);
        lcd.print("Bad");
      }
      else
      {
        lcd.setCursor(12,1);
        lcd.print("Well");
      }
    }
  }
  delay(5000);
  lcd.clear();
}
