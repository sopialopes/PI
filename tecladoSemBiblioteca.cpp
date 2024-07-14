//Código teclado sem a biblioteca 
#define L1 11
#define L2 10
#define L3 9
#define L4 8
#define C1 5
#define C2 4 
#define C3 3 
#define C4 2

const int LINHAS[] = {11, 10, 9, 8};

char mapaTeclas[4][4] = {{'1', '2', '3', 'A'},
                         {'4', '5', '6', 'B'},
                         {'7', '8', '9', 'C'},
                         {'*', '0', '#', 'D'}};

void imp(int linha, int coluna) {
  Serial.print(mapaTeclas[linha][coluna]); 
  Serial.print("Linha: ");
  Serial.print(linha); 
  Serial.print("Coluna: ");
  Serial.print(coluna); 
}

void setup() {
  /*for(int i = 0; i <= 3; i++)
    pinMode(linha[i], OUTPUT);*/
  //linhas
  pinMode(L1, OUTPUT); 
  pinMode(L2, OUTPUT); 
  pinMode(L3, OUTPUT); 
  pinMode(L4, OUTPUT); 

  //colunas 
  pinMode(C1, INPUT_PULLUP); 
  pinMode(C2, INPUT_PULLUP); 
  pinMode(C3, INPUT_PULLUP); 
  pinMode(C4, INPUT_PULLUP); 

  Serial.begin(9600); 
}

void loop() {
  for(int porta = 8; porta <= 11; porta--) {
    digitalWrite(L1, HIGH); 
    digitalWrite(L2, HIGH); 
    digitalWrite(L3, HIGH); 
    digitalWrite(L4, HIGH); 
    digitalWrite(porta, LOW); 

    if(digitalRead(L4) == LOW) {
      imp(porta-8,3);
      while(digitalRead(L4) ==LOW){
      }
    }

     if(digitalRead(L3) == LOW) {
      imp(porta-8,2);
      while(digitalRead(L3) ==LOW){
      }
    }

     if(digitalRead(L2) == LOW) {
      imp(porta-8,1);
      while(digitalRead(L2) ==LOW){
      }
    }

     if(digitalRead(L1) == LOW) {
      imp(porta-8,0);
      while(digitalRead(L1) ==LOW){
      }
    }
  }

}

