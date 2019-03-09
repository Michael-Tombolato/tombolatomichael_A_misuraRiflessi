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
int tRandom;
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
  tRandom = random(1000, 4000);
  delay(tRandom);
  digitalWrite(led, HIGH);
  while (stato == LOW)
  {
    stato = digitalRead(button);
    tempoLed = millis();
    if (stato == HIGH)
    {
      digitalWrite(led, LOW);
      tempoLed = millis() - tRandom;
      lcd.setCursor(0,0);
      lcd.print(tempoLed);
      lcd.setCursor(0,1);
      if (tempoLed > 5000)
      {
        lcd.print("Bad");
      }
      else
      {
        lcd.print("Well");
      }
    }
  }
  stato = LOW;
  tRandom = random(1000, 4000);
  delay(tRandom);
  digitalWrite(buzzer, HIGH);
  while (stato == LOW)
  {
    stato = digitalRead(button);
    tempoSuono = millis();
    if (stato == HIGH)
    {
      digitalWrite(buzzer, LOW);
      tempoSuono = millis() - tRandom - tempoLed;
      lcd.setCursor(0, 0);
      lcd.print(tempoSuono);
      lcd.setCursor(0,1);
      if (tempoSuono > 5000)
      {
        lcd.print("Bad");
      }
      else
      {
        lcd.print("Well");
      }
    }
  }
}
