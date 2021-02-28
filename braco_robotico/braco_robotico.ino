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
#define fechada 1000
#define aberta 200
#define DEBUG
 
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
int vlr_delay = 10;
int prof_max = 800;
int prof_atu = 0;

void setup()
{
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println(F("|================================================|"));
    Serial.println(F("|========== Arduino com braço robótico ==========|"));
    Serial.println(F("|================================================|"));
  #endif
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
  Serial.println("Centro");
  posicao_centro();
  delay(2000);
  Serial.println("Direita");
  lado_direito(100);
  delay(2000);  
  Serial.println("Subir");
  subir(700);  
  delay(2000);
  Serial.println("Abre");
  garra(900, 0);
  delay(1000);
  Serial.println("Para frente");
  para_frente(500);
  delay(1000);
  Serial.println("Fecha");
  garra(1000, 1);
  delay(2000);
  Serial.println("Para tras");
  para_tras(0);
  delay(1000);  
  Serial.println("Descer");
  descer(250);
  delay(2000);
  Serial.println("Esquerda");
  lado_esquerdo(900);
  
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

void garra(int vlr_garra, int movimento){
   // movimento = 0: abrir;
   // movimento = 1: fechar;
   if (movimento == 0){
      val = map(500, 0, 1023, 0, 179);
      myservoGarra.write(val);     
   } else{
      if (vlr_garra < 1001){
         x = 500;
         for(y=0; y < 50 ; y = y + 1){
            x = x + 10;
            if (x >= vlr_garra) {
               y = 50;
            } else {      
              val = map(x, 0, 1023, 0, 179);
              myservoGarra.write(val);                 
              delay(10);
           } 
         }        
      }    
   }
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
        delay(10);
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
        delay(10);
      } 
    }
  }  
}

void lado_direito(int teste)
{ 
  if ((teste > direita) && (teste < centro)){
    Serial.println("Vai para direita");
    x = lado;
    for(y=0; y < 50 ; y = y++){
      x = x - 10;
      if (x <= teste) {
        Serial.println("Não vai mais direita");
        y = 50;
      } else {      
         val = map(x, 0, 1023, 0, 179); 
         myservoBase.write(val); 
         lado = x;
         delay(vlr_delay);
      } 
    }
  }  
}

void lado_esquerdo(int teste)
{ 
  if ((teste < esquerda) && (teste > centro)){
    Serial.println("Vai para esquerda");
    x = lado;
    for(y=0; y < 50 ; y = y++){
      x = x + 10;
      if (x >= teste) {
        Serial.println("Não vai mais esquerda");
        y = 50;
      } else {      
         val = map(x, 0, 1023, 0, 179); 
         myservoBase.write(val); 
         lado = x;
         delay(vlr_delay);
      } 
    }
  }  
}

void posicao_centro()
{  
  if (lado != centro){  
    x = lado;   
    for(y=0; y < 50 ; y = y + 1){
       if (lado < 500){
         x = x + 10;
         if (x >= centro) {
           y = 50;
         } else {      
           val = map(x, 0, 1023, 0, 179);
           myservoBase.write(val); 
           lado = x;
         }        
      }else{
        x = x - 10;
        if (x <= centro) {
             y = 50;
        } else {      
           val = map(x, 0, 1023, 0, 179);
           myservoBase.write(val); 
           lado = x;
        }                                
      } 
      delay(vlr_delay);
    }
  }
}

void para_frente(int vlr_frente){  
  if (vlr_frente < prof_max){  
    x = prof_atu;   
    for(y=0; y < 50 ; y = y + 1){
       if (lado < 500){
         x = x + 10;
         if (x >= vlr_frente) {
           y = 50;
         } else {      
           val = map(x, 0, 1023, 0, 179); 
           myservoProfundidade.write(val);  
         }        
      }      
    }
    prof_atu = x;
    delay(vlr_delay);
  }
} 

void para_tras(int vlr_tras){  
  if (vlr_tras > 0 ){  
    x = prof_atu;   
    for(y=0; y < 50 ; y = y + 1){
       if (lado < 500){
         x = x - 10;
         if (x >= vlr_tras) {
           y = 50;
         } else {      
           val = map(x, 0, 1023, 0, 179); 
           myservoProfundidade.write(val);  
         }        
      }      
    }
    prof_atu = x;
    delay(vlr_delay);
  }
}   
