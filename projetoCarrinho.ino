// === DEFINIÇÃO DE PINOS ===

// Sensores de fogo
#define sensorFogoEsquerdo A2
#define sensorFogoFrente A1
#define sensorFogoDireita A0

// Bomba e servo motor
#define bombaDeAgua A5
#define servoMotor A4

// Ponte H (motores)
#define ENA 10
#define EN1 9
#define EN2 8
#define EN3 6
#define EN4 5
#define ENB 4

// === VARIÁVEIS ===
int valorSensorEsquerdo;

int valorSensorFrente;
int valorSensorDireito;

// === CONFIGURAÇÃO INICIAL ===
void setup() {
  Serial.begin(9600);

  // Sensores
  pinMode(sensorFogoEsquerdo, INPUT);
  pinMode(sensorFogoFrente, INPUT);
  pinMode(sensorFogoDireita, INPUT);

  // Motores
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Bomba e servo
  pinMode(bombaDeAgua, OUTPUT);
  pinMode(servoMotor, OUTPUT);

  Serial.println("Iniciando sistema de detecção de fogo...");
}

// === LOOP PRINCIPAL ===
void loop() {
  valorSensorEsquerdo = analogRead(sensorFogoEsquerdo);
  valorSensorFrente = analogRead(sensorFogoFrente);
  valorSensorDireito = analogRead(sensorFogoDireita);

  Serial.print("Esquerda: ");
  Serial.print(valorSensorEsquerdo);
  Serial.print(" | Frente: ");
  Serial.print(valorSensorFrente);
  Serial.print(" | Direita: ");
  Serial.println(valorSensorDireito);

  // === LÓGICA DE MOVIMENTO ===
  if (valorSensorFrente >= 250) {
    // Fogo na frente
    parar();
    digitalWrite(bombaDeAgua, HIGH); // liga a bomba
    delay(3000);                     // joga água por 3 segundos
    digitalWrite(bombaDeAgua, LOW);  // desliga a bomba
  } 
  else if (valorSensorEsquerdo >= 250) {
    esquerda(); // vira pra esquerda
  } 
  else if (valorSensorDireito >= 250) {
    direita();  // vira pra direita
  } 
  else {
    andar();    // segue em frente
  }

  delay(100);
}

// === FUNÇÕES DE MOVIMENTO ===

// Andar pra frente
void andar() {
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

// Parar
void parar() {
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Virar à direita
void direita() {
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

// Virar à esquerda
void esquerda() {
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}
