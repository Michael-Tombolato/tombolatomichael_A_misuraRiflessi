int led = 13;
int buzzer = 11;
int button = 9;
int stato;
int tRandom;
int tempoLed;
int tempoSuono;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Premere un qualsiasi tasto per dar via al test");
  while(Serial.available() == 0)
  {
    
  }
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
      tempoLed = tempoLed-tRandom;//Errore
      Serial.println(tempoLed);
    }
  }
  stato = LOW;
  tRandom = random(1000, 4000);
  delay(tRandom);
  tone(buzzer, HIGH);
  while (stato == LOW)
  {
    stato = digitalRead(button);
    tempoSuono = millis();
    if (stato == HIGH)
    {
      digitalWrite(buzzer, LOW); 
    }
  }
}
