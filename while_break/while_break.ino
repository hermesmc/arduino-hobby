#define pinBotao 2

void setup() {
  // put your setup code here, to run once:
  //INPUT_PULLUP = não precisa de resistor
  pinMode(pinBotao, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int n3 = 0;

   // Laço dos números
   numeros:
   for (int n1 = 0; n1 < 50 ; n1++){
    Serial.print(char((n1 % 10) + 48));
    if(digitalRead(pinBotao) == LOW){
      delay(400);
      break; 
     } 
     delay(50);
   }
   Serial.println();

   // laço letras maiúsculas
   letrasMaiusculas:
   int n2 = 0;
   while (n2 < 50) {
      Serial.print(char((n2 % 25) + 65));
      n2++;
      if(digitalRead(pinBotao) == LOW) {
          delay(400);
          continue; 
      }
      delay(50);
   }
   Serial.println(); 

   // laço letras minúsculas
   letrasMinusculas:
   do {
      n3 = random(25);
      Serial.print(char(n3 + 97));
      if (digitalRead(pinBotao) == LOW){
          delay(400);
          Serial.println();
          goto letrasMaiusculas;
      }
      delay(50);
   } while (n3 != 16);
   Serial.println(); 
}
