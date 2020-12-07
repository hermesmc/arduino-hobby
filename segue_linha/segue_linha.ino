#define DEBUG  
//Parametros dos motores
#define pinEnableMotorD 3      //Porta Digital PWM~
#define pinEnableMotorE 9     //Porta Digital PWM~
#define pinSentido1MotorD 2
#define pinSentido2MotorD 4
#define pinSentido1MotorE 8
#define pinSentido2MotorE 10

#define veloc0 0
#define veloc1 80
#define veloc2 180
#define veloc3 255

int pinLed1 = 13;
int pinLed2 = 12;
int pinLedD = 6;
int pinLedE = 7;

float valorLDR1;
float valorLDR2;
float minimo = 85;
float maximo = 1025;
float luminosidade1;
float luminosidade2;
float lumInit1;
float lumInit2;
float lumInitTtl1;
float lumInitTtl2;

// INICIALIZAÇAO --------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
    #ifdef DEBUG
    Serial.begin(9600);
    Serial.println(F("|================================================|"));
    Serial.println(F("|= Arduino com sensor de obstáculos ultrasônico =|"));
    Serial.println(F("|================================================|"));
  #endif
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT); 
  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLedD, OUTPUT);
  pinMode(pinLedE, OUTPUT);
  pinMode(pinEnableMotorD, OUTPUT);
  pinMode(pinEnableMotorE, OUTPUT);
  pinMode(pinSentido1MotorD, OUTPUT);
  pinMode(pinSentido1MotorE, OUTPUT);  
  pinMode(pinSentido2MotorD, OUTPUT);
  pinMode(pinSentido2MotorE, OUTPUT);    

  // Verifica luminosidade para iniciar o robô
  acenderLeds();
  int repeticoes = 6;
  for (int I = 0; I < repeticoes; I++){
    valorLDR1 = analogRead(A1);
    valorLDR2 = analogRead(A2);
    lumInit1 =  calcLuminosidade(valorLDR1);
    lumInitTtl1 = lumInitTtl1 + lumInit1;
    Serial.println(lumInit1);
    lumInit2 =  calcLuminosidade(valorLDR2);
    lumInitTtl2 = lumInitTtl2 + lumInit2;
    Serial.println(lumInit2);
    delay(1000);
  }
  piscaLeds(5);
  delay(1000);
  acenderLeds();
  lumInitTtl1 = (lumInitTtl1/repeticoes);
  lumInitTtl2 = (lumInitTtl2/repeticoes); 
  Serial.println(lumInitTtl1);
  Serial.println(lumInitTtl2);
  Serial.println("===========================================");
}

// PRINCIPAL --------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:
  int ok = 0;
  valorLDR1 = analogRead(A1);
  valorLDR2 = analogRead(A2);
  luminosidade1 = calcLuminosidade(valorLDR1);
  if (lumInitTtl1 < luminosidade1){
      Serial.println("ANDA D");
      ok = 0;
      andarPraFrenteD(veloc1);
    }else{       
      Serial.println("sem luz - 1");
      ok++;
    }
  luminosidade2 = calcLuminosidade(valorLDR2);
  if (lumInitTtl2  < luminosidade2){
     Serial.println("ANDA E");
     andarPraFrenteE(veloc1);
     if (ok == 0) {
        ok = 0;
      }   
  }else{
     Serial.println("sem luz - 2");
     ok = ok + 2;
  }
  if (ok == 0) {
  } else {
     Serial.println(ok);
     if (ok == 1){
        obstaculoD();
     }
     
     if (ok == 2){
        obstaculoE();
     }
     
     if (ok == 3){
        obstaculoDE();
     }
     digitalWrite(pinLedD, LOW);
     digitalWrite(pinLedE, LOW);
  }       
  delay(10); 
}

// -------------------------------------------------------------------------

float calcLuminosidade(float luminosidadeInit){
  float lum = 0;
  lum = ((luminosidadeInit - minimo ) / (maximo - minimo)) * 10;
  lum = (lum - 10) * -1;
  return lum;
}
void andarPraFrenteD(int velocidade) {
  Serial.println("andando D");
  analogWrite(pinSentido2MotorD, velocidade);   
  digitalWrite(pinSentido1MotorD, LOW);  
  
}

void andarPraFrenteE(int velocidade) {
  Serial.println("andando E");
  analogWrite(pinSentido2MotorE, velocidade);   
  digitalWrite(pinSentido1MotorE, LOW); 
}

void andarPraTrasD(int velocidade) {
  Serial.println("pra tras D");
  digitalWrite(pinSentido2MotorD, LOW);   
  analogWrite(pinSentido1MotorD, velocidade); 
}

void andarPraTrasE(int velocidade) {
  Serial.println("pra tras E");
  digitalWrite(pinSentido2MotorE, LOW);   
  analogWrite(pinSentido1MotorE, velocidade); 
}

void pararMotorD() {
  Serial.println("parar D");
  digitalWrite(pinSentido1MotorD, LOW);
  digitalWrite(pinSentido2MotorD, LOW);
}

void pararMotorE() {  
  Serial.println("parar E");
  digitalWrite(pinSentido1MotorE, LOW);       
  digitalWrite(pinSentido2MotorE, LOW);       
}

void obstaculoD() {
  digitalWrite(pinLedD, HIGH);
  pararMotorD();
  pararMotorE();
  delay(500);
  andarPraFrenteD(veloc1);
  delay(100);
  pararMotorD();
}

void obstaculoE() {
  digitalWrite(pinLedE, HIGH);
  pararMotorD();
  pararMotorE();
  delay(500);
  andarPraFrenteE(veloc1);
  delay(100);
  pararMotorE();
}

void obstaculoDE() {
  pararMotorD();
  pararMotorE();
  delay(500);
  andarPraFrenteE(veloc1);
  delay(100);}

// --- LEDS
void acenderLeds() {
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
}

void apagarLeds() {
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
}

void piscaLeds(int repeticoes){  
  for ( int i = 0; i < repeticoes; i++){
    apagarLeds();
    delay(100);
    acenderLeds();
    delay(100);
  }
  apagarLeds();
}
