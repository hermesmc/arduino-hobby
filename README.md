# Estrutura básica de um programa para o Arduíno:

    void setup() {
      // put your setup code here, to run once:

    }

    void loop() {
      // put your main code here, to run repeatedly:

    }

A declaração de variáveis antes das declarações void são do tipo global. Já a declaração feita dentro de cada um dos voids é local.

## No setup, podemos declarar qual porta e função vai ser utilizada:

    void setup() {
      pinMode(11, OUTPUT);
    }

Neste exemplo a porta 9 será utilizada para enviar energia

## No loop, podemos declarar o que a porta utilizada vai fazer. No exemplo abaixo, a porta 11 vai enviar energia por 3 segundos e depois desligar por 5 segundos. Como está dentro do loop, fará isso de forma infinita.

    void loop() {
      // put your main code here, to run repeatedly:

      digitalWrite(11, HIGH);
      delay(3000);
      digitalWrite(11, LOW);  
      delay(5000);
    }

## No exemplo abaixo temos um código para um semáforo manual. Nele temos exemplos de declaração de variáves, utilização de botão para receber uma informação e utilização de condições para determinar o que deve ser feito. O deleay abaixo está presente só como exemplo. Para este código, não é necessária a sua presença.

    
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

## Portas analógicas

Ao contrário da porta digital, que tem os valores de 0 ou 5 volts, a porta analógica permite a variação de ensão entre 0 e 5 volts.
