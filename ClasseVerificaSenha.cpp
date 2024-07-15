#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // define o endereço do LCD como 0x27 para um display de 16 caracteres e 2 linhas

int linha[4] = {4, 5, 6, 7};
int coluna[4] = {8, 9, 10, 11}; 

class VerificaSenha {
  private:
  char mapaTeclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
  };
  String senha; 
  String entrada = ""; 
  int tentativas = 0; 
  unsigned long ultimoErro = 0;
  long long tempoBloqueio; 
  bool bloqueado = false; 
   
  public: 
  VerificaSenha(String s, long long tmp_bloq) {
    senha = s; 
    tempoBloqueio = tmp_bloq; 
  } 

  void escreveTela(int linha, int coluna, String palavra) {
    lcd.setCursor(linha, coluna);
    lcd.print(palavra);
  }

  // Função para mapear a linha e coluna para a tecla correspondente
  char getTecla(int linha, int coluna) {
    int linhaIndex = linha - 4;
    int colunaIndex = coluna - 8;
    char tecla = ' ';
    if (linhaIndex >= 0 && linhaIndex < 4 && colunaIndex >= 0 && colunaIndex < 4) {
      tecla = mapaTeclas[linhaIndex][colunaIndex];
    }
    return tecla;
  }

  // Função para Escrever os caracteres no Display
  void escreveNoDisplay(int linha, int coluna) {
    if (bloqueado) return; // Verifica se está bloqueado
    
    char tecla = getTecla(linha, coluna); // Função para obter a tecla pressionada
    if (tecla != ' ') {
      lcd.print('*'); // Mostra * no lugar do caractere real
      entrada += tecla; // Armazena o caractere real na variável de entrada
  
      if (entrada.length() == senha.length()) {
        lcd.setCursor(0, 1);
        if (entrada == senha) {
          lcd.print("Senha correta");
          delay(1500);
          lcd.clear(); 
          escreveTela(6, 0, "SEJA"); 
          escreveTela(3, 1, "BEM-VINDO :)"); 
          delay(1000); 
          lcd.clear();
          entrada = "";
          tentativas = 0;
        } else {
          lcd.print("Senha incorreta");
          tentativas++;
          if (tentativas >= 3) {
            lcd.clear(); 
            escreveTela(0, 0, "Teclado bloqueado!"); 
            bloqueado = true;
            ultimoErro = millis(); // Marca o momento do bloqueio
            delay(2000);
            lcd.clear();
          } else {
            delay(1500);
            lcd.clear(); 
            escreveTela(0, 0, "Tente novamente!"); 
            delay(1000); 
            lcd.clear();
          }
          entrada = "";
          lcd.setCursor(0, 0);
        }
      }
    }
  }

  void init() {
    // Configura as linhas do teclado como saídas
    for (int i = 0; i < 4; i++) {
      pinMode(linha[i], OUTPUT);
    }
  
    // Configura as colunas do teclado como entradas
    for (int j = 0; j < 4; j++) {
      pinMode(coluna[j], INPUT);
    }
  }

  void deixaBloqueado() {
    if (!bloqueado) {
      for (int linhaX = 4; linhaX < 8; linhaX++) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(linha[i], LOW);
        }
        // Coloca em 5V a linhaX
        digitalWrite(linhaX, HIGH);
        
        for (int j = 0; j < 4; j++) {
          if (digitalRead(coluna[j]) == HIGH) { 
            escreveNoDisplay(linhaX, coluna[j]);
            while (digitalRead(coluna[j]) == HIGH) {}
          }
        }
      }
    } else {
      // Verifica se o tempo de bloqueio expirou
      if (millis() - ultimoErro >= tempoBloqueio) {
        bloqueado = false;
        lcd.clear();
        escreveTela(0, 0, "Digite a senha:");
        lcd.setCursor(0, 1);
      }
    }
  }
};


VerificaSenha usuario1("2405", 10000); 

void setup() {
  lcd.begin(16, 2); 
  lcd.backlight();
  usuario1.escreveTela(7, 0, "PI"); 
  usuario1.escreveTela(0, 1, "SOPHIA E HINACIO");
  delay(1000); 
  lcd.clear();
  lcd.setCursor(0, 0);
  usuario1.init(); 
}

void loop() {
  if (!usuario1.bloqueado) {
    usuario1.escreveNoDisplay(4, 8); // Atualiza o display e verifica a senha
  } else {
    usuario1.deixaBloqueado(); // Verifica se está bloqueado e, se necessário, desbloqueia
  }
}
