// BLOG Eletrogate
// Kit Braço Robótico MDF com Arduino
// https://blog.eletrogate.com/kit-braco-robotico-mdf-com-arduino/
 
 
#define potpin1  2
#define potpin2  3
#define potpin3  4
#define potpin4  5
 
#include <Servo.h>
 
Servo myservoBase;  // Objeto servo para controlar a base
Servo myservoGarra;  //Objeto servo para controlar a garra
Servo myservoAltura; //Objeto servo para controlar a altura do braço
Servo myservoProfundidade; //Objeto servo para profundidade a altura do braço
 
 
int val;    // variable to read the value from the analog pin
 
void setup()
{
  //Associa cada objeto a um pino pwm
  myservoBase.attach(3);
  myservoGarra.attach(5);
  myservoAltura.attach(9);
  myservoProfundidade.attach(11);
}
 
void loop()
{
 
  val = map(500, 0, 1023, 0, 179);
  myservoBase.write(val);
 
  val = map(1000, 0, 1023, 0, 179);
  myservoGarra.write(val);
 
  val = map(200, 0, 1023, 0, 179);
  myservoAltura.write(val);
 
  val = map(0, 0, 1023, 0, 179);
  myservoProfundidade.write(val);
 
  delay(2000);

  val = map(500, 0, 1023, 0, 179); // Pra frente 500 - para direita 0 - 1000 esquerda
  myservoBase.write(val);
 
  val = map(200, 0, 1023, 0, 179); // 1000 garra fechada - 200 garra aberta
  myservoGarra.write(val);
 
  val = map(200, 0, 1023, 0, 179); // 1000 altura máxima - 200 minímo
  myservoAltura.write(val);
 
  val = map(0, 0, 1023, 0, 179); // 800 prof máxima - 0 mínima
  myservoProfundidade.write(val);
 
  delay(2000);
}
