/* Copie 100% deste documento e cole na área de programação do Arduino IDE */
/* *********************** Nervo Teste do Manual do Mundo ***********************

   Criado por: Anderson Harayashiki Moreira

   Rev.: 02

   Data: 25.02.2018

   Guia de conexão:

   LED indicativo: Pino 2

   Labirinto: Pino 3

   Botão: Pino 7

   Buzzer: Pino 9

   Módulo Relé (Sirene): Pino 10

 ***************************************************************************** */

// Declaração dos pinos utilizados do Arduino
int pinoLED = 2;
int pinoLabirinto = 3;
int pinoBuzzer = 9;
int pinoSirene = 10;

// Declaração das variáveis auxiliares
int nivel = 0;
long int tempoAnterior = 0;
int deltaT = 200;
int tomBuzzer = 3000;
int estadoBotao = LOW;
int estadoBuzzer = LOW;

// A função setup é apenas executada uma vez ao se iniciar o Arduino, aqui configuramos nossa placa Arduino

void setup() {
  // Pinos configurados como entrada:
  pinMode(pinoLabirinto, INPUT_PULLUP); // Configurando a entrada como INPUT_PULLUP, utilizamos o resistor interno pull-up do Arduino

  //=======  pinMode(pinoBotao, INPUT);
  // Pinos configurados como saída:

  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoSirene, OUTPUT);
  digitalWrite(pinoLED, HIGH);
  digitalWrite(pinoSirene, HIGH); //noTone(pinoSirene);
  Serial.begin(9600);
}

// A função loop é executada repetitivamente até se desligar o Arduino

void loop() {
  Serial.println(nivel);
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
  if (nivel == 2) {
    deltaT = 100;
    tomBuzzer = 3500;
  }
  if (nivel == 3) {
    deltaT = 50;
    tomBuzzer = 4000;
  }
  if (nivel == 4) {
    noTone(pinoBuzzer);//digitalWrite(pinoBuzzer, LOW);
    while (1) {
      digitalWrite(pinoSirene, LOW); //tone(pinoSirene, 4000);
    }

  }
  if (((millis() - tempoAnterior) > deltaT) && (nivel >= 1)) {
    if (estadoBuzzer) {
      tone(pinoBuzzer, tomBuzzer);
    }
    else {
      noTone(pinoBuzzer);
    }
    estadoBuzzer = !estadoBuzzer;
    tempoAnterior = millis();
  }
}
