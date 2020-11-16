/*Pinagem do arduino*/
//motor_A
int IN1 = 2 ;
int IN2 = 4 ;
int velocidadeA = 3;
//motor_B
int IN3 = 7 ;
int IN4 = 6 ;
int velocidadeB = 5;
//variavel auxiliar
int velocidade = 0;
//Inicializa Pinos
void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(velocidadeA,OUTPUT);
  pinMode(velocidadeB,OUTPUT);
}
void loop(){
  praFrente();
  delay(3000);
  praTras();
  delay(3000);
  parar();
  delay(3000);
}

void praFrente(){
  //direita  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(velocidadeA,120);
  //esquerda
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(velocidadeB,120);
}

void praTras(){
  //direita  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(velocidadeA,120);
  //esquerda
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(velocidadeB,120);
}

void parar(){
  //direita  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(velocidadeA,0);
  //esquerda
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(velocidadeB,0);
}
