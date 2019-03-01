int led = 13;
int buzzer = 11;
#define BUTTON = 9;
int cont = 0;
int tempoLed = 0;
int tempoSuono = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  cont = digitalRead(BUTTON);
  for (int i = 0; cont == HIGH; i++)
  {
    tempoLed = tempoLed + 1;
    if (cont == HIGH)
    {
      digitalWrite(LED, LOW);
    } 
  }
}
