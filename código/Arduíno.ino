#include <Servo.h>

const int ledVerde = 2;
const int ledAmarelo = 4;
const int ledVermelho = 5;

const int sensorNivel = 3;
const int sensorTampa = 6;

Servo tampa;
const int pinoServo = 9;

bool tampaAberta = false;

void setup() {

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.begin(9600);

  tampa.attach(pinoServo);
  tampa.write(0);

}

void loop() {

  int distanciaNivel = lerDistancia(sensorNivel);

  if (distanciaNivel > 20) {

    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);

  }
  else if (distanciaNivel > 10) {

    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);

  }
  else {

    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

  }

  int distanciaTampa = lerDistancia(sensorTampa);

  Serial.print("Nivel: ");
  Serial.print(distanciaNivel);
  Serial.print(" cm | Tampa: ");
  Serial.print(distanciaTampa);
  Serial.println(" cm");

  if (distanciaTampa > 0 && distanciaTampa < 20) {

    if (!tampaAberta) {

      Serial.println("Abrindo tampa...");
      tampa.write(90);
      tampaAberta = true;

    }

  } else {

    if (tampaAberta) {

      delay(2000);
      Serial.println("Fechando tampa...");
      tampa.write(0);
      tampaAberta = false;

    }

  }

  delay(200);

}

long lerDistancia(int pino){

  pinMode(pino, OUTPUT);

  digitalWrite(pino, LOW);
  delayMicroseconds(2);

  digitalWrite(pino, HIGH);
  delayMicroseconds(5);

  digitalWrite(pino, LOW);

  pinMode(pino, INPUT);

  long duracao = pulseIn(pino, HIGH, 30000);

  if (duracao == 0) return 999;

  return duracao / 29 / 2;

}
