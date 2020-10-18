
// declaração de variaveis: deve iniciar com letra e não deve ter espaços e unico simbolo é o _  
// declarando aqui as variáveis são globais
int intervalo = 200;
int intervalo2 = 2000;

  
void setup() {
  // put your setup code here, to run once:
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // declarando aqui as variáveis são locais
  int intervalo3 = 200;  
    
  digitalWrite(9, HIGH); 
  digitalWrite(10, LOW);
  delay(intervalo);
  digitalWrite(9, LOW); 
  digitalWrite(10, HIGH);
  delay(intervalo2);

}
