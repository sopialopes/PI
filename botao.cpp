#define LED_VERMELHO 8
#define LED_AMARELO 9
#define BOTAO 10
#define MAXIMO 2 

int botao_clicado = 0; 
int botao_liberado = 0; 
int ciclo = 0; 

void setup() {
 pinMode(LED_VERMELHO, OUTPUT); 
 pinMode(LED_AMARELO, OUTPUT); 
 pinMode(BOTAO, INPUT);
}

void liga_vermelho(int tmp) {
  digitalWrite(LED_VERMELHO, HIGH); 
  digitalWrite(LED_AMARELO, LOW);
  delay(tmp); 
}

void liga_amarelo(int tmp) {
  digitalWrite(LED_VERMELHO, LOW); 
  digitalWrite(LED_AMARELO, HIGH);
  delay(tmp); 
}

void troca_led() {
  if(ciclo == 0) {
    liga_vermelho(3000); 
  }else {
    liga_amarelo(3000); 
  }
  ciclo++; 
  if(ciclo>MAXIMO-1) {
    ciclo = 0; 
  }
}

void verifica_botao() {
  if(digitalRead(BOTAO) == HIGH) {
    botao_clicado = 1; 
    botao_liberado = 0; 
  }else {
    botao_liberado = 1; 
  }
  if((botao_clicado == 1) and (botao_liberado == 1)) {
    botao_clicado = 0; 
    botao_liberado = 0; 
    troca_led(); 
  }
}

void loop() {
  verifica_botao(); 
}

