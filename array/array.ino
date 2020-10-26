//Constante
#define pinBotao 2
int numero = 10;
boolean botaoAnt = false;
boolean botaoAtu = false;
int portas[8] = {10, 9, 6, 7, 8, 11, 12, 5};
                            //a,b,c,d,e,f,g,ponto
byte displayConfig[11][8] = {{1,1,1,1,1,1,0,0}, //Digito 0
                             {0,1,1,0,0,0,0,0}, //Digito 1
                             {1,1,0,1,1,0,1,0}, //Digito 2
                             {1,1,1,1,0,0,1,0}, //Digito 3
                             {0,1,1,0,0,1,1,0}, //Digito 4
                             {1,0,1,1,0,1,1,0}, //Digito 5
                             {1,0,1,1,1,1,1,0}, //Digito 6
                             {1,1,1,0,0,0,0,0}, //Digito 7
                             {1,1,1,1,1,1,1,0}, //Digito 8
                             {1,1,1,1,0,1,1,0}, //Digito 9
                             {0,0,0,0,0,0,0,0}}; //Tudo apagado
void setup() {
  // put your setup code here, to run once:
  pinMode(pinBotao, INPUT);
  int x;
  for ( x = 0; x < 9 ; x++){
    pinMode(portas[x], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  botaoAtu = digitalRead(pinBotao);
  if (botaoAtu && !botaoAnt){
    numero++;
    if (numero > 9){
      numero = 0;  
    }
  }
  botaoAnt = botaoAtu;

  for (int y = 0; y < 8; y++){
    digitalWrite(portas[y],displayConfig[numero][y]);     
  } 
}
