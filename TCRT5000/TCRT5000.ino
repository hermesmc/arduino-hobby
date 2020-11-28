#define DEBUG  
int pinoSensor = 7; //PINO DIGITAL UTILIZADO PELO SENSOR
   
void setup(){ 
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println(F("|================================================|"));
    Serial.println(F("|= Arduino com sensor de linhas                 =|"));
    Serial.println(F("|================================================|"));
  #endif 
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
}  
   
void loop(){
  if (digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
        Serial.println("COM LUZ");
  }else{//SENÃO, FAZ
        Serial.println("sem luz");
  } 
  delay(2000);   
}
