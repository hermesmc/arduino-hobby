
//Declarando array:
int pinLed[9] = {13,12,11,10,9,8,7,6,5};
int qtdLeds = 9;
int qtdArray = qtdLeds - 1;
int numeroLed;
int on = 0 ;
char digitado;

void setup() {
  // put your setup code here, to run once:
  int x;
  
  for(x = 0; x < 9; x = x + 1){
     pinMode(pinLed[x], OUTPUT);
  }  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitado = ' ';
  numeroLed = 0;
  while (digitado != 'P' ){
     digitalWrite(pinLed[numeroLed], LOW);    
     numeroLed++;
     if (numeroLed > qtdArray){
        numeroLed = 0;
     }
     digitalWrite(pinLed[numeroLed], HIGH);    
     if (Serial.available()){
        digitado = Serial.read();
     }
     delay(50);     
  }
  delay(3000);
}
