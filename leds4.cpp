#define LED_VERMELHO 8
#define LED_BRANCO 9
#define LED_VERDE 10
#define LED_AMARELO 11

void setup() {
 pinMode(LED_VERMELHO, OUTPUT); 
 pinMode(LED_BRANCO, OUTPUT); 
 pinMode(LED_VERDE, OUTPUT); 
 pinMode(LED_AMARELO, OUTPUT); 
}

void ligar_vermelho(int tmp) {
  digitalWrite(LED_VERMELHO, HIGH); 
  digitalWrite(LED_BRANCO, LOW); 
  digitalWrite(LED_VERDE, LOW); 
  digitalWrite(LED_AMARELO, LOW); 
  delay(tmp); 
}

void ligar_branco(int tmp) {
  digitalWrite(LED_VERMELHO, LOW); 
  digitalWrite(LED_BRANCO, HIGH); 
  digitalWrite(LED_VERDE, LOW); 
  digitalWrite(LED_AMARELO, LOW); 
  delay(tmp); 
}

void ligar_verde(int tmp) {
  digitalWrite(LED_VERMELHO, LOW); 
  digitalWrite(LED_BRANCO, LOW); 
  digitalWrite(LED_VERDE, HIGH); 
  digitalWrite(LED_AMARELO, LOW); 
  delay(tmp); 
}

void ligar_amarelo(int tmp) {
  digitalWrite(LED_VERMELHO, LOW); 
  digitalWrite(LED_BRANCO, LOW); 
  digitalWrite(LED_VERDE, LOW); 
  digitalWrite(LED_AMARELO, HIGH); 
  delay(tmp); 
}

void loop() {
  ligar_vermelho(3000); 
  ligar_branco(3000);
  ligar_verde(3000); 
  ligar_amarelo(3000); 
}

