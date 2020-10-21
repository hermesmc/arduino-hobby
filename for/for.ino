
//Declarando array:
int pinLed[4] = {13,12,11,10};
int y;

void setup() {
  // put your setup code here, to run once:
  int x;
  for(x = 0; x < 4; x = x + 1){
     pinMode(pinLed[x], OUTPUT);
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  int y;
 
  for(y=0; y < 4 ; y = y + 1){
    delay(100); 
    digitalWrite(pinLed[y], HIGH);    
    if (y > 0){
      digitalWrite(pinLed[y - 1], LOW);    
    }
    if (y == 0){
      digitalWrite(pinLed[3], LOW);    
    }
  }
  
  for(y=0; y < 4 ; y = y + 1){
    delay(100); 
    digitalWrite(pinLed[3 - y], HIGH);    
    if (y > 0){
      digitalWrite(pinLed[(3 - y) + 1], LOW);    
    }
  }
  
}
