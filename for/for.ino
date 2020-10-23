
//Declarando array:
int pinLed[9] = {13,12,11,10,9,8,7,6,5};
int y;

int pinBotao = 4;
int estadoBotao;
int estadoBotaoAnt;
int on = 0 ;

void setup() {
  // put your setup code here, to run once:
  int x;
  
  for(x = 0; x < 9; x = x + 1){
     pinMode(pinLed[x], OUTPUT);
  }  
  estadoBotaoAnt = digitalRead(pinBotao); //situação anterior do botão
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoBotao = digitalRead(pinBotao);
  if (estadoBotao == HIGH){
     if (on == 0){
       on = 1; 
     }else{       
       on = 0;
     }
  }
  for(y=0; y < 9 ; y = y + 1){
     delay(100); 
     digitalWrite(pinLed[y], HIGH);    
     if (y > 0){
       digitalWrite(pinLed[y - 1], LOW);    
     }
     if (y == 0){
       digitalWrite(pinLed[8], LOW);    
     }
  }
  if (on == 0){
    for(y=0; y < 9 ; y = y + 1){
      delay(100); 
      digitalWrite(pinLed[8 - y], HIGH);    
      if (y > 0){
        digitalWrite(pinLed[(8 - y) + 1], LOW);    
      }
    }
  }    
}
