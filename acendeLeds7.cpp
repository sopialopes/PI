#define VERMELHO 8
#define AMARELO 9
#define VERDE 10
#define AZUL 11
#define LARANJA 12
#define BRANCO 13
#define BOTAO 7

void setup() {
  pinMode(VERMELHO, OUTPUT); 
  pinMode(AMARELO, OUTPUT); 
  pinMode(VERDE, OUTPUT); 
  pinMode(AZUL, OUTPUT); 
  pinMode(LARANJA, OUTPUT); 
  pinMode(BRANCO, OUTPUT); 
}

void ligar_vermelho(int tmp) {
  digitalWrite(VERMELHO, HIGH); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}

void ligar_amarelo(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}


void ligar_verde(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}

void ligar_azul(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
#define VERMELHO 8
#define AMARELO 9
#define VERDE 10
#define AZUL 11
#define LARANJA 12
#define BRANCO 13
#define BOTAO 7

void setup() {
  pinMode(VERMELHO, OUTPUT); 
  pinMode(AMARELO, OUTPUT); 
  pinMode(VERDE, OUTPUT); 
  pinMode(AZUL, OUTPUT); 
  pinMode(LARANJA, OUTPUT); 
  pinMode(BRANCO, OUTPUT); 
}

void ligar_vermelho(int tmp) {
  digitalWrite(VERMELHO, HIGH); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}

void ligar_amarelo(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}


void ligar_verde(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}

void ligar_azul(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}


void ligar_laranja(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, HIGH);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}

void ligar_branco(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, HIGH);
  delay(tmp);   
}

void desligado_todos() {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
}

void botao_ligado(int tmp) {
  ligar_vermelho(tmp); 
  ligar_amarelo(tmp); 
  ligar_verde(tmp); 
  ligar_azul(tmp); 
  ligar_laranja(tmp); 
  ligar_branco(tmp); 
}

void loop() {
  if(digitalRead(BOTAO) == HIGH) {
    botao_ligado(1000); 
  }else {
    desligado_todos;
  }
}  digitalWrite(AZUL, HIGH);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}


void ligar_laranja(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, HIGH);
  digitalWrite(BRANCO, LOW);
  delay(tmp);   
}

void ligar_branco(int tmp) {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, HIGH);
  delay(tmp);   
}

void desligado_todos() {
  digitalWrite(VERMELHO, LOW); 
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(BRANCO, LOW);
}

void botao_ligado(int tmp) {
  ligar_vermelho(tmp); 
  ligar_amarelo(tmp); 
  ligar_verde(tmp); 
  ligar_azul(tmp); 
  ligar_laranja(tmp); 
  ligar_branco(tmp); 
}

void loop() {
  if(digitalRead(BOTAO) == HIGH) {
    botao_ligado(1000); 
  }else {
    desligado_todos;
  }
}

