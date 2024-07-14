#define LED_VERMELHO 8
#define LED_AMARELO 9
#define BOTAO 10

class Btn {
 public:
 int botao_clicado; 
 int botao_liberado; 
 int pino; 
 Btn(int p) {
  pino = p;
  botao_clicado = 0; 
  botao_liberado = 0; 
 }
 bool press() {
  if(digitalRead(pino) == HIGH)  {
    botao_clicado = 1; 
    botao_liberado = 0; 
  }else {
    botao_liberado = 1; 
  }
  if((botao_clicado == 1) and (botao_liberado == 1)) {
    botao_clicado = 0; 
    botao_liberado = 0; 
    return true;
  }else {
      return false;
  }
 }
}; 

class Cor {
private: 
  void cor_led(int cor1, int cor2) {
    digitalWrite(pino1, cor1);  //HIGH == 1 | LOW == 0
    digitalWrite(pino2, cor2); 
  }

public: 
  int pino1, pino2, ciclo, maximo; 
  Cor(int p1, int p2) {
    pino1 = p1; 
    pino2 = p2; 
    ciclo = 0; 
    maximo = 2; 
  }
  void troca_led() {
    if(ciclo == 0) {
      cor_led(1,0); 
    }else {
      cor_led(0,1); 
    }
    ciclo++; 
    if(ciclo>maximo-1) {
      ciclo = 0; 
    }
  }

}; 

Btn botao(BOTAO); 
Cor cor(LED_VERMELHO, LED_AMARELO); 

void setup() {
 pinMode(LED_VERMELHO, OUTPUT); 
 pinMode(LED_AMARELO, OUTPUT); 
 pinMode(botao1, INPUT);
}

void loop() {
    if(botao.press()){
      cor.troca_led(); 
  }
}

