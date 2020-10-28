#define pinPIR 2
int pinLed[9] = {12,11,10,9,8,7,6,5,4};
int x;

void setup() {
  // put your setup code here, to run once:
  for(x = 0; x < 9; x++){
     pinMode(pinLed[x], OUTPUT);
  }
  pinMode(pinPIR, INPUT);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  bool valorPIR = false;
  valorPIR = digitalRead(pinPIR);

  for(x = 0; x < 9; x++){
    if (valorPIR){  
      digitalWrite(pinLed[x], HIGH);          
    }else{
      digitalWrite(pinLed[x], LOW);          
    }  
  }    
    
}
