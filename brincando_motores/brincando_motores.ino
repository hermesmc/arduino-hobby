#define pinBotaoA 5

#define pinPotenciometro A0
#define pinEnableMotorA 9      //Porta Digital PWM~
#define pinEnableMotorB 10     //Porta Digital PWM~

#define pinSentido1MotorA 3
#define pinSentido2MotorA 2

#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

byte estadoA = 0;
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA;

void setup() {
  
  pinMode(pinBotaoA, INPUT_PULLUP);
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);

  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
}

void loop() {

  estadoBotaoA = digitalRead(pinBotaoA);
  if (!estadoBotaoA && estadoAntBotaoA) {
     if ((millis() - delayBotaoA) > 20) {
        estadoA++;
        if (estadoA > 3) {
           estadoA = 0;
        }
        delayBotaoA = millis();
     }
  } else if (estadoBotaoA != estadoAntBotaoA) {
        delayBotaoA = millis();    
  }
  estadoAntBotaoA = estadoBotaoA;

  if (estadoA == 0) {
     analogWrite(pinEnableMotorA, 0);
     
  } else if (estadoA == 2) {
     analogWrite(pinEnableMotorA, 255); 
     digitalWrite(pinSentido1MotorA, HIGH);
     digitalWrite(pinSentido2MotorA, HIGH);    
     analogWrite(pinEnableMotorB, 255); 
     digitalWrite(pinSentido1MotorB, HIGH);
     digitalWrite(pinSentido2MotorB, HIGH);     
  } else {    
     analogWrite(pinEnableMotorA, map(analogRead(pinPotenciometro), 0, 1023, 0, 255)); 

     if (estadoA == 1) {

        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);        
        
     } else { // estadoA == 3

        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);      
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);              
     }
  }
  delay(300);   
}
