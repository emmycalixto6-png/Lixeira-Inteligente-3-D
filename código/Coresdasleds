// 1. DEFINIÇÃO DOS PINOS
const int ledVerde = 2;
const int ledAmarelo = 1;
const int ledVermelho = 0;
const int pinoSensor = 3; // Pino de sinal do sensor

void setup() {
  // Configura os LEDs como saídas de energia
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  // 2. COMANDO PARA FAZER O SENSOR LER A DISTÂNCIA (EM CENTÍMETROS)
  int distancia = lerDistancia(pinoSensor);

  // 3. LÓGICA DA LIXEIRA (Exemplo para uma lixeira de 30cm de altura)
  
  if (distancia > 20) {
    // Se o lixo está longe (mais de 20cm do topo), a lixeira está VAZIA
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } 
  else if (distancia <= 20 && distancia > 10) {
    // Se o lixo está no meio (entre 10cm e 20cm do topo), está PELA METADE
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } 
  else {
    // Se o lixo está muito perto do topo (menos de 10cm), está CHEIA
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  delay(500); // Espera meio segundo para atualizar a leitura
}

// --- FUNÇÃO AUXILIAR (O Tinkercad usa isso para ler o sensor de 3 pinos) ---
long lerDistancia(int pino) {
  pinMode(pino, OUTPUT);
  digitalWrite(pino, LOW);
  delayMicroseconds(2);
  digitalWrite(pino, HIGH);
  delayMicroseconds(5);
  digitalWrite(pino, LOW);
  pinMode(pino, INPUT);
  return pulseIn(pino, HIGH) / 29 / 2; // Retorna a distância direto em cm
}
