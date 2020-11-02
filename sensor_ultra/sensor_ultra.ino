#include <HCSR04.h>  

//Definição de pinos
#define pingTrig 8
#define pingEcho 9
#define pinLed 4


//Definição de parâmetros
#define distObstaculo 10 // distancia em centimetros
#define tempoLeitura 50 //minimo de intervalo para cada leitura
#define medidaDist 5 //quantidade de medidas armazenadas

#define DEBUG  

// Variaveis
boolean       obstaculo = false;
boolean       parar = false;
boolean       novaLeitura;
boolean       mediaSensor[medidaDist];
byte          posicao;
byte          contaObstaculo = 0;
unsigned long controleLeitura; 

//instanciando objetos
HCSR04 sensorHCSR04(pingTrig, pingEcho);


  void setup() {
  // put your setup code here, to run once:
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println(F("|================================================|"));
    Serial.println(F("|= Arduino com sensor de obstáculos ultrasônico =|"));
    Serial.println(F("|================================================|"));
  #endif

  pinMode(pinLed, OUTPUT); 

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
        Serial.println("PARAR!");
        digitalWrite(pinLed,HIGH);
      }
    } else {
      if(parar == true){
        parar = false;
        Serial.println("Seguir.");
        digitalWrite(pinLed,LOW);
      }
    }
  
    contaObstaculo = 0;
    if ( posicao > medidaDist ){
      posicao = 0;
    }
  }
 
}
