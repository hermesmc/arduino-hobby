# Estrutura básica de um programa para o Arduíno:

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    
}

A declaração de variáveis antes das declarações void são do tipo global. Já a declaração feita dentro de cada um dos voids é local.

# No setup, podemos declarar qual porta e função vai ser utilizada:

void setup() {
  pinMode(11, OUTPUT);
}

Neste exemplo a porta 9 será utilizada para enviar energia

# No loop, podemos declarar o que a porta utilizada vai fazer. No exemplo abaixo, a porta 11 vai enviar energia por 3 segundos e depois desligar por 5 segundos. COmo está dentro do loop, fará isso de forma infinita.

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(11, HIGH);
  delay(3000);
  digitalWrite(11, LOW);  
  delay(5000);
}
