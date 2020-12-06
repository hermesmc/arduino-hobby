
// INCLUSÃO DE BIBLIOTECAS
#include              <PushButton.h>
#include "sons.h"

// DEFINIÇÕES DE PINOS
#define pinBotAm 8
#define pinBotAz 9
#define pinBotVd 10
#define pinBotVm 11
#define pinPot A1

#define ledAm 4
#define ledAz 5
#define ledVd 6
#define ledVm 7

#define pinBuzzer 2

// DEFINIÇÕES
#define Buzz1 1047
#define Buzz2 587
#define Buzz3 659
#define Buzz4 698

#define nivelMax 50

#define DEBUG
// INSTANCIANDO OBJETOS
PushButton botAm(pinBotAm,30);
PushButton botAz(pinBotAz,30);
PushButton botVd(pinBotVd,30);
PushButton botVm(pinBotVm,30);


// DECLARAÇÃO DE FUNÇÕES
void vezArduino();
void vezUsuario();
void trocaVez();
bool confere();
bool myDelay(int tempo);

// DECLARAÇÃO DE VARIÁVEIS
byte sequencia[nivelMax];
byte sequenciaUsuario[nivelMax];

byte Leds[] = {ledAm, ledAz, ledVd, ledVm};
int Buzz[] = {Buzz1, Buzz2, Buzz3, Buzz4};

byte contador = 0;
unsigned int velocidade = 1000;
unsigned int tempoLimite;

bool timeOut = false;

void setup() {
  Serial.begin(9600);

  for (byte i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }

  for (byte i = 4; i < 8; i++) {
    digitalWrite(i, LOW);
  }

  pinMode(13, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  randomSeed(analogRead(A0));
  
  velocidade = map(analogRead(pinPot),0,1023,100,1000);
  tempoLimite = map(velocidade,100,1000,1500,3000);
  
  delay(1000);
  
#ifdef DEBUG
  Serial.println("Fim Setup");
#endif
}

void loop() {
  vezArduino();
  trocaVez();
  vezUsuario();

  if (confere() == 0) {  //Se errou

    //Toca musica
    for (byte nota = 0 ; nota < 156 ; nota++) {
       tone(pinBuzzer, mario[nota], duracaoMario[nota]);
       if (myDelay(pausaMario[nota]) == 0) break;
    }
    
    while (true) {
      for (byte i = 0 ; i < 4; i++) {
        digitalWrite(Leds[i], HIGH);
      }
      delay(150);
      for (byte i = 0 ; i < 4; i++) {
        digitalWrite(Leds[i], LOW);
      }
      delay(500);
    }
  }

  if (contador == nivelMax) {
    digitalWrite(13, HIGH);

    for (byte nota = 0; nota < 12 ; nota++) {
      tone(pinBuzzer, vitoria[nota], duracaoVitoria);
      delay(duracaoVitoria);
    }

    //LOOP INFINITO
    while (true) {
      for (byte i = 0 ; i < 4; i++) {
        digitalWrite(Leds[i], HIGH);
        delay(150);
      }

      for (byte i = 4 ; i > 0; i--) {
        digitalWrite(Leds[i - 1], LOW);
        delay(150);
      }
    }
  }

  trocaVez();

} // FIM DO LOOP

// IMPLEMENTO DE FUNÇÕES
void vezArduino() {
  sequencia[contador] = random(0, 4);

  for (byte i = 0 ; i <= contador; i++) {
    digitalWrite(Leds[sequencia[i]], HIGH);
    tone(pinBuzzer, Buzz[sequencia[i]], velocidade);
    delay(velocidade);
    digitalWrite(Leds[sequencia[i]], LOW);
    delay(velocidade / 2);
  }

  contador++;
}

void vezUsuario() {
  unsigned long controleTempo = millis();
  byte leitura = 0;

  while (leitura < contador) {
    botAm.button_loop(); botAz.button_loop(); botVd.button_loop(); botVm.button_loop();

    if (botAm.pressed()) {
      sequenciaUsuario[leitura] = 0;
      controleTempo = millis();
      leitura++;

      digitalWrite(Leds[1], LOW);
      digitalWrite(Leds[2], LOW);
      digitalWrite(Leds[3], LOW);
      
      digitalWrite(Leds[0], HIGH);
      tone(pinBuzzer, Buzz[0], velocidade);      
      
    } else if (botAz.pressed()) {
      sequenciaUsuario[leitura] = 1;
      controleTempo = millis();
      leitura++;

      digitalWrite(Leds[0], LOW);
      digitalWrite(Leds[2], LOW);
      digitalWrite(Leds[3], LOW);
      
      digitalWrite(Leds[1], HIGH);
      tone(pinBuzzer, Buzz[1], velocidade);
      
    } else if (botVd.pressed()) {
      sequenciaUsuario[leitura] = 2;
      controleTempo = millis();
      leitura++;

      digitalWrite(Leds[0], LOW);
      digitalWrite(Leds[1], LOW);
      digitalWrite(Leds[3], LOW);

      digitalWrite(Leds[2], HIGH);
      tone(pinBuzzer, Buzz[2], velocidade);
      
    } else if (botVm.pressed()) {
      sequenciaUsuario[leitura] = 3;
      controleTempo = millis();
      leitura++;

      digitalWrite(Leds[0], LOW);
      digitalWrite(Leds[1], LOW);
      digitalWrite(Leds[2], LOW);

      digitalWrite(Leds[3], HIGH);
      tone(pinBuzzer, Buzz[3], velocidade);
    }

    if (millis() > controleTempo + tempoLimite){
      timeOut = true;
      break;
    }

  }

 
  digitalWrite(Leds[0], LOW);
  digitalWrite(Leds[1], LOW);
  digitalWrite(Leds[2], LOW);
  digitalWrite(Leds[3], LOW);

  delay(velocidade/2);
}

// FUNÇÃO PARA INDICAR A TROCA DE VEZ
void trocaVez() {
  for (byte i = 0 ; i < 4; i++) {
    digitalWrite(Leds[i], HIGH);
    delay(50);
  }

  for (byte i = 4 ; i > 0; i--) {
    digitalWrite(Leds[i - 1], LOW);
    delay(50);
  }

  for (byte i = 0 ; i < 4; i++) {
    digitalWrite(Leds[i], HIGH);
  }
  delay(250);
  for (byte i = 0 ; i < 4; i++) {
    digitalWrite(Leds[i], LOW);
  }
  //delay(500);
}

bool confere() {
  bool resultado = true;

  for (byte i = 0; i < contador; i++) {
    if (sequencia[i] != sequenciaUsuario[i] || timeOut == true) {
      resultado = false;
      for (byte nota = 0; nota < 2 ; nota++) {
        tone(pinBuzzer, errado[nota], duracaoErrado[nota]);
        delay(duracaoErrado[nota]);
      }
      break;
    }
  }

  return resultado;
}

bool myDelay(int tempo) {
  unsigned long controleDelay = millis();

  while ( millis() - controleDelay < tempo ) {
    botAm.button_loop(); botAz.button_loop(); botVd.button_loop(); botVm.button_loop();
    if (botAm.pressed() || botAz.pressed() || botVd.pressed() || botVm.pressed()) {
      return 0;
    }
  }
  return 1;
}
