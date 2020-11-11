#define DEBUG  
//Parametros dos motores
#define pinEnableMotorA 10      //Porta Digital PWM~
#define pinEnableMotorB 11     //Porta Digital PWM~
#define pinSentido1MotorA 3
#define pinSentido1MotorB 6


int pinLed1 = 13;
int pinLed2 = 12;
int pinLedF = 8;

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

void setup() {
  // put your setup code here, to run once:
    #ifdef DEBUG
    Serial.begin(9600);
    Serial.println(F("|================================================|"));
    Serial.println(F("|= Arduino com sensor de obstáculos ultrasônico =|"));
    Serial.println(F("|================================================|"));
  #endif
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLedF, OUTPUT);
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT); 
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);
  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);  

  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  for (int I = 0; I < 3; I++){
    valorLDR1 = analogRead(A1);
    valorLDR2 = analogRead(A2);
    lumInit1 = ((valorLDR1 - minimo ) / (maximo - minimo)) * 10;
    lumInit1 = ((lumInit1 - 10) * -1);
    lumInitTtl1 = lumInitTtl1 + lumInit1;
    Serial.println(lumInit1);
    lumInit2 = ((valorLDR2 - minimo ) / (maximo - minimo)) * 10;
    lumInit2 = ((lumInit2 - 10) * -1);
    lumInitTtl2 = lumInitTtl2 + lumInit2;
    Serial.println(lumInit2);
    delay(1000);
  }
  lumInitTtl1 = (lumInitTtl1/3);
  lumInitTtl2 = (lumInitTtl2/3); 
  Serial.println(lumInitTtl1);
  Serial.println(lumInitTtl2);
  Serial.println("===========================================");
}

void loop() {
  // put your main code here, to run repeatedly:
  int ok = 0;
  valorLDR1 = analogRead(A1);
  valorLDR2 = analogRead(A2);
  luminosidade1 = ((valorLDR1 - minimo ) / (maximo - minimo)) * 10;
  luminosidade1 = (luminosidade1 - 10) * -1;
    if (lumInitTtl1 < luminosidade1){
      Serial.println(luminosidade1);
      ok = 0;
      andarPraFrenteD();
    }else{       
      Serial.println("Sem luz - 1");
      ok = 1;
      pararMotorD(); 
    }
  luminosidade2 = ((valorLDR2 - minimo ) / (maximo - minimo)) * 10;
  luminosidade2 = (luminosidade2 - 10) * -1;
  if (lumInitTtl2  < luminosidade2){
     Serial.println(luminosidade2);
     andarPraFrenteE();
     if (ok == 0) {
        ok = 0;
      }   
  }else{
     Serial.println("Sem luz - 2");
     pararMotorE();
     if (ok == 0) {
        ok = 1;
     }   
  }
  if (ok == 0) {
     digitalWrite(pinLedF, LOW);
  } else {
     digitalWrite(pinLedF, HIGH);
  }       
  delay(100); 
}

void andarPraFrente() {
     digitalWrite(pinSentido1MotorA, HIGH); 
     digitalWrite(pinSentido1MotorB, HIGH);
}

void andarPraFrenteD() {
     analogWrite(pinSentido1MotorA, 100);     
}

void andarPraFrenteE() {
      //digitalWrite(pinSentido1MotorB, HIGH);
     analogWrite(pinSentido1MotorB, 100);   
}

void andarPraTras() {
     digitalWrite(pinEnableMotorA, HIGH);   
     digitalWrite(pinSentido1MotorA, HIGH);
     
     digitalWrite(pinEnableMotorB, HIGH); 
     digitalWrite(pinSentido1MotorB, HIGH);
     
}
void pararMotor() {
     digitalWrite(pinEnableMotorA, LOW);   
     digitalWrite(pinSentido1MotorA, LOW);
     
     digitalWrite(pinEnableMotorB, LOW);    
     digitalWrite(pinSentido1MotorB, LOW);
     
}

void pararMotorE() {  
     digitalWrite(pinEnableMotorB, LOW);    
     digitalWrite(pinSentido1MotorB, LOW);
       
}

void pararMotorD() {
     digitalWrite(pinEnableMotorA, LOW);   
     digitalWrite(pinSentido1MotorA, LOW);
}
