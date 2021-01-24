#include <Servo.h>

// define pinos dos servos
#define pinServ1 3
#define pinServ2 5
#define pinServ3 9
#define pinServ4 11

// nomeia os servos
Servo serv1,serv2,serv3,serv4;

// cria as variavies dos angulos de cada motor
int motor1,motor2,motor3,motor4;

void setup() {
  // atribui pinos dos servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);  
}

void loop(){

  // leitura dos potenciometros
  motor1 = map(500,0,1023,0,180);
  motor2 = map(150,0,1023,0,180);
  motor3 = map(0,0,1023,85,180);
  motor4 = map(7000,0,1023,20,43);  
  serv1.write(motor1);
  serv2.write(motor2);
  serv3.write(motor3);
  serv4.write(motor4);
  delay(2000);
  motor3 = map(-1000,0,1023,0,180); 
  serv3.write(motor3);  
  delay(2000);
  motor3 = map(5000,0,1023,0,180); 
  serv3.write(motor3);
  delay(2000);
}
