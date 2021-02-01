// BLOG Eletrogate
// Kit Braço Robótico MDF com Arduino
// https://blog.eletrogate.com/kit-braco-robotico-mdf-com-arduino/
 
 
#define potpin1  2
#define potpin2  3
#define potpin3  4
#define potpin4  5
#define direita  0
#define centro   500
#define esquerda 1000
 
#include <Servo.h>
 
Servo myservoBase;  // Objeto servo para controlar a base
Servo myservoGarra;  //Objeto servo para controlar a garra
Servo myservoAltura; //Objeto servo para controlar a altura do braço
Servo myservoProfundidade; //Objeto servo para profundidade a altura do braço
 
 
int val;    // variable to read the value from the analog pin
int x;
int y;
int altura; 
int lado; 
void setup()
{
  //Associa cada objeto a um pino pwm
  myservoBase.attach(3);
  myservoGarra.attach(5);
  myservoAltura.attach(9);
  myservoProfundidade.attach(11);
  inicial();
  delay(5000);
}
 
void loop()
{
  delay(2000);
  posicao_centro();
  subir(1000);
  delay(2000);
  descer(250);
  lado_direito(200);
}

void inicial(){
  altura = 250;
  lado = centro;
  val = map(centro, 0, 1023, 0, 179); // Pra frente 500 - para direita 0 - 1000 esquerda
  myservoBase.write(val); 
  val = map(1000, 0, 1023, 0, 179); // 1000 garra fechada - 200 garra aberta
  myservoGarra.write(val); 
  val = map(altura, 0, 1023, 0, 179); // 1000 altura máxima - 200 minímo
  myservoAltura.write(val); 
  val = map(000, 0, 1023, 0, 179); // 800 prof máxima - 0 mínima
  myservoProfundidade.write(val);  
}

void subir(int max)
{
  if (max > altura){ 
    x = altura;
    for(y=0; y < 50 ; y = y + 1){
      x = x + 10;
      if (x >= max) {
        y = 50;
      } else {      
        val = map(x, 0, 1023, 0, 179); // 1000 altura máxima - 200 minímo
        myservoAltura.write(val);
        altura = x;
        delay(20);
      } 
    }
  }  
}  

void descer(int min)
{ 
  if (min < altura){ 
    x = altura;
    for(y=0; y < 50 ; y = y++){
      x = x - 10;
      if (x <= min) {
        y = 50;
      } else {      
        val = map(x, 0, 1023, 0, 179); 
        myservoAltura.write(val);
        altura = x;
        delay(20);
      } 
    }
  }  
}

void lado_direito(int teste)
{ 
  if ((teste > direita) && (teste < centro)){
    x = lado;
    for(y=0; y < 50 ; y = y++){
      x = x - 10;
      if (x <= teste) {
        y = 50;
      } else {      
         val = map(x, 0, 1023, 0, 179); 
         myservoBase.write(val); 
         lado = x;
         delay(20);
      } 
    }
  }  
}

void posicao_centro()
{
  x = lado;   
  for(y=0; y < 50 ; y = y + 1){
    x = x + 10;
    if (x <= centro) {
      y = 50;
    } else {      
       val = map(x, 0, 1023, 0, 179);
       myservoBase.write(val); 
       lado = x;
       delay(20);
    } 
  }
}
