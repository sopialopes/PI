//TESTE INIVIAL DO HORARIO, FUNCIONANDO NO TINKERCAD
//FUNCIONA NA PLACA

#include <Wire.h>  
#include <LiquidCrystal_I2C.h>  

// Define o endereço do LCD como 0x27 para um display de 16 caracteres e 2 linhas  
LiquidCrystal_I2C lcd(0x27, 16, 2);  

int linha[4] = {4, 5, 6, 7};  
int coluna[4] = {8, 9, 10, 11};  

class VerificaSenha {  
  private:  
    String senha;  
    String entrada = "";  
    int tentativas = 0;  
    unsigned long ultimoErro = 0;  
    unsigned long tempoBloqueio;   
    bool bloqueado = false;  

    char mapaTeclas[4][4] = {  
      {'1', '2', '3', 'A'},  
      {'4', '5', '6', 'B'},  
      {'7', '8', '9', 'C'},  
      {'*', '0', '#', 'D'}  
    };  

    char getTecla(int linha, int coluna) {  
      int linhaIndex = linha - 4;  
      int colunaIndex = coluna - 8;  
      if (linhaIndex >= 0 && linhaIndex < 4 && colunaIndex >= 0 && colunaIndex < 4) {  
        return mapaTeclas[linhaIndex][colunaIndex];  
      }  
      return 0;  
    }  

  public:  
    VerificaSenha(String s, unsigned long tmp_bloq) {  
      senha = s;  
      tempoBloqueio = tmp_bloq;  
    }  

    void escreveTela(int linha, int coluna, String palavra) {  
      lcd.setCursor(coluna, linha);  // Ajuste para ordem correta dos parâmetros  
      lcd.print(palavra);  
    }  

    void init() {  
      lcd.begin(16, 2);  
      lcd.init();  
      lcd.backlight();  

      // Configura as linhas do teclado como saídas  
      for (int i = 0; i < 4; i++) {  
        pinMode(linha[i], OUTPUT);  
      }  

      // Configura as colunas do teclado como entradas  
      for (int j = 0; j < 4; j++) {  
        pinMode(coluna[j], INPUT);  
      }  

      escreveTela(0, 7, "PI");  
      escreveTela(1, 0, "SOPHIA E HINACIO");  
      delay(1500);  
      lcd.clear();  
      
      // Exibir a hora até que uma tecla seja pressionada  
      mostrarHoraAteTeclaPressionada();  
      
      lcd.clear();  
      escreveTela(0, 0, "Digite a senha:");  
      lcd.setCursor(0, 1);  
    }  

    void mostrarHoraAteTeclaPressionada() {  
      unsigned long tempoInicio = millis();  
      
      while (true) {  
        // Calcula o tempo decorrido  
        unsigned long elapsedTime = millis() - tempoInicio;  

        // Converte milissegundos em horas, minutos e segundos  
        int horas = (elapsedTime / 3600000) % 24;  
        int minutos = (elapsedTime / 60000) % 60;  
        int segundos = (elapsedTime / 1000) % 60;  

        // Formata a hora como "hh:mm:ss"  
        String horaFormatada = String(horas).length() < 2 ? "0" + String(horas) : String(horas);  
        horaFormatada += ":";  
        horaFormatada += String(minutos).length() < 2 ? "0" + String(minutos) : String(minutos);  
        horaFormatada += ":";  
        horaFormatada += String(segundos).length() < 2 ? "0" + String(segundos) : String(segundos);  

        // Atualiza o LCD com a hora  
        lcd.clear();  
        escreveTela(0, 0, "Hora:");  
        escreveTela(1, 0, horaFormatada);  
        delay(500);  

        // Verifica se alguma tecla foi pressionada  
        for (int i = 0; i < 4; i++) {  
          digitalWrite(linha[i], LOW); // Ativa a linha  
          for (int j = 0; j < 4; j++) {  
            if (digitalRead(coluna[j]) == HIGH) {  
              return; // Sai do loop se uma tecla for pressionada  
            }  
          }  
          digitalWrite(linha[i], HIGH); // Desativa a linha  
        }  
      }  
    }  

    void escreveNoDisplay(int linha, int coluna) {  
      if (bloqueado == true) {  
        return; // Verifica se está bloqueado  
      }  

      char tecla = getTecla(linha, coluna);  
      if (tecla != 0) {  
        lcd.print('*');  
        entrada += tecla;  

        if (entrada.length() == senha.length()) {  
          lcd.setCursor(0, 1);  
          if (entrada == senha) {  
            lcd.print("Senha correta");  
            delay(1500);  
            lcd.clear();  
            escreveTela(0, 0, "SEJA");  
            escreveTela(1, 0, "BEM-VINDO :)");  
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
              ultimoErro = millis();  
              delay(2000);  
              lcd.clear();  
            } else {  
              delay(1000);  
              lcd.clear();  
              escreveTela(0, 0, "Tente novamente!");  
              delay(1000);  
              lcd.clear();  
            }  
            entrada = "";  
            escreveTela(0, 0, "Digite a senha:");  
            lcd.setCursor(0, 1);  
          }  
        }  
      }  
    }  

    void verificaTeclado() {  
      if (bloqueado == false) {  
        for (int linhaX = 4; linhaX < 8; linhaX++) {  
          for (int i = 0; i < 4; i++) {  
            digitalWrite(linha[i], LOW);  
          }  
          digitalWrite(linhaX, HIGH);  

          for (int j = 0; j < 4; j++) {  
            if (digitalRead(coluna[j]) == HIGH) {  
              escreveNoDisplay(linhaX, coluna[j]);  
              while (digitalRead(coluna[j]) == HIGH) {}  
            }  
          }  
        }  
      } else {  
        if (millis() - ultimoErro >= tempoBloqueio) {  
          bloqueado = false;  
          lcd.clear();  
          escreveTela(0, 0, "Digite a senha:");  
          lcd.setCursor(0, 1);  
        }  
      }  
    }  

    bool isBloqueado() {  
      return bloqueado;  
    }  
};  

VerificaSenha usuario1("A23", 10000);  

void setup() {  
  usuario1.init();  
}  

void loop() {  
  usuario1.verificaTeclado();  
}
