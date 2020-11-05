#include <HCSR04.h>  

//Definição de pinos
#define pingTrig 8
#define pingEcho 9


//Definição de parâmetros
#define distObstaculo 27 // distancia em centimetros
#define tempoLeitura 50 //minimo de intervalo para cada leitura
#define medidaDist 5 //quantidade de medidas armazenadas

//Parametros dos motores
#define pinEnableMotorA 10      //Porta Digital PWM~
#define pinEnableMotorB 11     //Porta Digital PWM~
#define pinSentido1MotorA 3
#define pinSentido2MotorA 2
#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

//#define DEBUG  

// Variaveis
boolean       obstaculo = false;
boolean       parar = false;
boolean       novaLeitura;
boolean       mediaSensor[medidaDist];
byte          posicao;
byte          contaObstaculo = 0;
unsigned long controleLeitura; 
int defLado = 0;
int pino1 = 12;
int pino2 = 13;


//instanciando objetos
HCSR04 sensorHCSR04(pingTrig, pingEcho);


void setup() {
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);
  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  // put your setup code here, to run once:
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println(F("|================================================|"));
    Serial.println(F("|= Arduino com sensor de obstáculos ultrasônico =|"));
    Serial.println(F("|================================================|"));
  #endif
  for (byte i = 0; i < medidaDist ; i++){
    mediaSensor[i] = 0;
    #ifdef DEBUG
      Serial.print("Setando posição "); Serial.print(i); Serial.println(" do Array como FALSE.");
    #endif
  }
  posicao = 0;  
  #ifdef DEBUG
    Serial.println("----- Fim do setup -----");
  #endif
  delay(2000);
}

void loop() {

  novaLeitura = false;
  
  if (millis() - controleLeitura > tempoLeitura){
    if (sensorHCSR04.dist() <= distObstaculo){
      obstaculo = true;
      novaLeitura = true;
    } else { 
      obstaculo = false;
      novaLeitura = true;
    }
    controleLeitura = millis();
  }

  if (novaLeitura == true){
    
    mediaSensor[posicao] = obstaculo;
    posicao = posicao + 1;
  
    for (byte i = 0 ; i < medidaDist ; i++){
      if (mediaSensor[i] == 1) contaObstaculo++;
    }
  
    if ( contaObstaculo >= ((medidaDist/2) +1)){
      if(parar == false){
        parar = true;
        pararMotor();
        digitalWrite(pino1, HIGH);
        digitalWrite(pino2, LOW);
        Serial.println("PARAR!");
        delay(500);
        if (defLado == 0) {
          defLado = 1;
          curvaPraTrasEsq();
        } else {
          defLado = 0;
          curvaPraTrasDir();
        }  
        delay(500);
        pararMotor();
      }
    } else {
      if(parar == true){
        parar = false;
        andarPraFrente();
        digitalWrite(pino1, LOW);
        digitalWrite(pino2, HIGH);
        Serial.println("Seguir.");
      }
    }
  
    contaObstaculo = 0;
    if ( posicao > medidaDist ){
      posicao = 0;
    }
  }
}

void andarPraFrente() {
     digitalWrite(pinEnableMotorA, HIGH);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, HIGH);
     digitalWrite(pinEnableMotorB, HIGH); 
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, HIGH);  
}

void andarPraTras() {
     digitalWrite(pinEnableMotorA, HIGH);   
     digitalWrite(pinSentido1MotorA, HIGH);
     digitalWrite(pinSentido2MotorA, LOW);
     digitalWrite(pinEnableMotorB, HIGH); 
     digitalWrite(pinSentido1MotorB, HIGH);
     digitalWrite(pinSentido2MotorB, LOW);  
}

void curvaPraTrasEsq() {
     digitalWrite(pinEnableMotorA, LOW);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, LOW);
     digitalWrite(pinEnableMotorB, HIGH); 
     digitalWrite(pinSentido1MotorB, HIGH);
     digitalWrite(pinSentido2MotorB, LOW);  
}

void curvaPraTrasDir() {
     digitalWrite(pinEnableMotorA, HIGH);   
     digitalWrite(pinSentido1MotorA, HIGH);
     digitalWrite(pinSentido2MotorA, LOW);
     digitalWrite(pinEnableMotorB, LOW); 
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, LOW);  
}

void pararMotor() {
     digitalWrite(pinEnableMotorA, LOW);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, LOW);    
     digitalWrite(pinEnableMotorB, LOW);    
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, LOW);  
}
