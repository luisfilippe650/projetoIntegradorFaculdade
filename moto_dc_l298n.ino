// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
  // Define all the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Inicializa com os motores desligados
  pararMotores();
}

void loop() {
  // Motor A e B para frente com velocidade média
  frente(150);
  delay(2000);

  // Motor A e B para trás com velocidade alta
  tras(255);
  delay(2000);

  // Para os motores
  pararMotores();
  delay(2000);
}

// Função para mover os dois motores para frente
void frente(int velocidade) {
  // Motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, velocidade);

  // Motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, velocidade);
}

// Função para mover os dois motores para trás
void tras(int velocidade) {
  // Motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, velocidade);

  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, velocidade);
}

// Função para parar os motores
void pararMotores() {
  // Motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
