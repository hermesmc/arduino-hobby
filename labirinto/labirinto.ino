int pinoLED  = 8;
int pinoLED1 = 7;
int pinoLED2 = 6;
int pinoLED3 = 5;
int pinoLabirinto = 3;
int pinoBuzzer = 9;

int nivel = 0;
long int tempoAnterior = 0;
int deltaT = 200;
int tomBuzzer = 3000;
int estadoBotao = LOW;
int estadoBuzzer = LOW;

void setup() {
  // Pinos configurados como entrada:
  pinMode(pinoLabirinto, INPUT_PULLUP); // Configurando a entrada como INPUT_PULLUP, utilizamos o resistor interno pull-up do Arduino

  nivel = 0;
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLED1, OUTPUT);
  pinMode(pinoLED2, OUTPUT);
  pinMode(pinoLED3, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  digitalWrite(pinoLED, HIGH);
  Serial.begin(9600);
}

void loop() {
  estadoBotao = digitalRead(pinoLabirinto);
  if (estadoBotao == LOW) {
    delay(50);
    estadoBotao = digitalRead(pinoLabirinto);
    while (!digitalRead(pinoLabirinto)) {
      delay(1);
    }
    if (estadoBotao == LOW) {
      nivel = nivel + 1;
    }
  }
  if (nivel == 1) {
    deltaT = 100;
    tomBuzzer = 3500;
    digitalWrite(pinoLED1, HIGH);
  }
  if (nivel == 2) {
    deltaT = 50;
    tomBuzzer = 4000;
    digitalWrite(pinoLED2, HIGH);
  }
  if (nivel == 3) {
    deltaT = 0;
    tomBuzzer = 4000;
    digitalWrite(pinoLED3, HIGH);
    estadoBuzzer = HIGH;
  }
  Serial.println(nivel);
  if (((millis() - tempoAnterior) > deltaT) && (nivel >= 1)) {
    if (estadoBuzzer) {
      Serial.println("Toca");
      tone(pinoBuzzer, tomBuzzer);
    }
    else {
      noTone(pinoBuzzer);
      Serial.println("Não toca");
    }
    estadoBuzzer = !estadoBuzzer;
    tempoAnterior = millis();
  }
  if (nivel == 3) {
    Serial.println("reseta");
    resetar();
  }
}

void resetar(){
  delay(5000);
  noTone(pinoBuzzer);  
  for( int i = 0; i < 10; i++){
    digitalWrite(pinoLED1, LOW);
    digitalWrite(pinoLED2, LOW);
    digitalWrite(pinoLED3, LOW);
    delay(150);
    digitalWrite(pinoLED1, HIGH);
    digitalWrite(pinoLED2, HIGH);
    digitalWrite(pinoLED3, HIGH);
    delay(150);
  }
  digitalWrite(pinoLED1, LOW);
  digitalWrite(pinoLED2, LOW);
  digitalWrite(pinoLED3, LOW);
  nivel = 0;
  tempoAnterior = 0;
  deltaT = 200;
  tomBuzzer = 3000;
  estadoBotao = LOW;
  estadoBuzzer = HIGH;  
}
