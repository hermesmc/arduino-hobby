#define DEBUG  
//Parametros dos motores
#define pinEnableMotorA 10      //Porta Digital PWM~
#define pinEnableMotorB 11     //Porta Digital PWM~
#define pinSentido1MotorA 3
#define pinSentido2MotorA 2
#define pinSentido1MotorB 6
#define pinSentido2MotorB 7

int pinLed1 = 13;
int pinLed2 = 12;

float valorLDR1;
float valorLDR2;
float minimo = 85;
float maximo = 1025;
float luminosidade1;
float luminosidade2;


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
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT); 
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);
  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  valorLDR1 = analogRead(A1);
  valorLDR2 = analogRead(A2);
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  
  luminosidade1 = ((valorLDR1 - minimo ) / (maximo - minimo)) * 10;
  luminosidade1 = (luminosidade1 - 10) * -1;
    if (9 < luminosidade1){
      Serial.println("LUZ--1");
      andarPraFrenteD();
    }else{       
       Serial.println("Sem luz - 1");
       pararMotorD(); 
    }
  luminosidade2 = ((valorLDR2 - minimo ) / (maximo - minimo)) * 10;
  luminosidade2 = (luminosidade2 - 10) * -1;
    if (8.5  < luminosidade2){
       Serial.println("LUZ--2");
       andarPraFrenteE();
    }else{
       Serial.println("Sem luz - 2");
       pararMotorE();
    }    
  delay(100); 
}

void andarPraFrente() {
     digitalWrite(pinEnableMotorA, HIGH);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, HIGH);
     digitalWrite(pinEnableMotorB, HIGH); 
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, HIGH);  
}

void andarPraFrenteD() {
     digitalWrite(pinEnableMotorA, HIGH);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, HIGH);
}

void andarPraFrenteE() {
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
void pararMotor() {
     digitalWrite(pinEnableMotorA, LOW);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, LOW);    
     digitalWrite(pinEnableMotorB, LOW);    
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, LOW);  
}

void pararMotorE() {  
     digitalWrite(pinEnableMotorB, LOW);    
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, LOW);  
}

void pararMotorD() {
     digitalWrite(pinEnableMotorA, LOW);   
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, LOW);  
}
