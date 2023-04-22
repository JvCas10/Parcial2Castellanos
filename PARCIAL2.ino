#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 8, d5 = 4, d6 = 3, d7 = 2, ct=9;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);
const int ledAzul = 5;
const int Buzzer = 6;
const int Motor = 7;

const int potenciometro = A3;
int valorPotenciometro;

void setup() {
  pinMode(ledAzul, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Motor, OUTPUT);
 
  analogWrite(ct,50);
  mylcd.begin(16, 2);

  Serial.begin(9600); 
}

void nada(int ledAzul){
  valorPotenciometro = analogRead(potenciometro);
  if (valorPotenciometro <= 250 ) {
    digitalWrite(ledAzul, LOW);

    mylcd.print("nada");
    delay(500);
    mylcd.clear();
  
  }
}

void luz(int ledAzul){
 if (valorPotenciometro > 250 && valorPotenciometro <= 500) {
    digitalWrite(ledAzul, HIGH);
    mylcd.print("Luz LED");
    delay(500);
    mylcd.clear();
  } else {
    digitalWrite(ledAzul, LOW);
  }
}

void buzzer(int pinbuzzer){
  valorPotenciometro = analogRead(potenciometro);
  int sol = 330;
  int la = 349;
  int si = 370;
  int frecuencias[] = {si, la, sol, la, sol};
  const int numFrecuencias = 5;
  valorPotenciometro = analogRead(potenciometro);
  if (valorPotenciometro > 500 && valorPotenciometro <= 750  ) { 
    for (int i = 0; i < 5; i++)
      {
        tone(6, frecuencias[i]);
        delay(500);
        noTone(pinbuzzer);
      }
    mylcd.print("Buzzer");  
    delay(500);
    mylcd.clear();
  } else {
    digitalWrite(Buzzer, LOW);
  }
}

void vent(int Motor){
  valorPotenciometro = analogRead(potenciometro);
  if (valorPotenciometro > 750) {
    digitalWrite(Motor, HIGH);
    mylcd.print("Ventilador");
    delay(500); 
    mylcd.clear();
  } else {
    digitalWrite(Motor, LOW);
  }
}

void loop() {
  Serial.println(valorPotenciometro);
  delay(50);
  nada(5);
  luz(5);
  buzzer(6);
  vent(7); 
}