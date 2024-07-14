//vantagem do define, uso de memória do dispositivo 
#define LED_VERDE 8 
#define LED_AMARELO 9
#define LED_VERMELHO 10

void setup(){
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void verde(int tmp) {
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  delay(tmp);
}

void amarelo(int tmp) {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  delay(tmp);

}

void vermelho(int tmp)
 {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(tmp);

 }
void loop(){
  verde(7000); 
   amarelo(7000); 
  vermelho(7000); 
}

