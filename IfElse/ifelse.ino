
int pinVermelho = 10;
int pinAmarelo = 9;
int pinVerde = 8;
int pinBotao = 7;
int faseSemaforo;
int estadoBotao;
int estadoBotaoAnt;

int pinPedVermelho = 3;
int pinPedVerde = 2;

int tempoPisca;
int estadoPisca;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinPedVerde, OUTPUT);  
  pinMode(pinPedVermelho, OUTPUT);  
  pinMode(pinBotao, INPUT);

  faseSemaforo = 1;
  estadoBotaoAnt = digitalRead(pinBotao); //situação anterior do botão
  tempoPisca = 0;
  estadoPisca = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:

  estadoBotao = digitalRead(pinBotao);
  if ((estadoBotao == LOW) && (estadoBotaoAnt == HIGH)){
    faseSemaforo = faseSemaforo + 1;
    if (faseSemaforo > 4 ){
      faseSemaforo = 1; 
    }
  }
  
  estadoBotaoAnt = estadoBotao;
  
  //Verde ON
  if(faseSemaforo == 1){
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);
    
    digitalWrite(pinPedVermelho, HIGH);
    digitalWrite(pinPedVerde, LOW);
  }

  //Amarelo ON
  if(faseSemaforo == 2){
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);
    
    digitalWrite(pinPedVermelho, HIGH);
    digitalWrite(pinPedVerde, LOW);    
  }

  //Vermelho ON
  if(faseSemaforo == 3){
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
    
    digitalWrite(pinPedVermelho, LOW);
    digitalWrite(pinPedVerde, HIGH);
  }

    //Semafor pedestre piscando
  if(faseSemaforo == 4){
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);

    tempoPisca = tempoPisca + 1;

    if (tempoPisca  == 400){
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    }
    digitalWrite(pinPedVermelho, estadoPisca);
    digitalWrite(pinPedVerde, LOW);
  }
  delay(1);
}
