//   LRF           Nodemcu
//   VCC-----------VCC 2,8V
//   RX------------D1
//   TX------------D2
//   GND-----------GND

#include <SoftwareSerial.h>
// Biblioteca para transformar pinos regulares como Tx e Rx
//#include <ESP8266WiFi.h> // Biblioteca para realizar a conexão Wi-Fi
#include <ESP8266WiFi.h>

const char* ssid = "familiadias";  // Nome da rede Wi-Fi
const char* password = "cambuiminas";  // Senha da rede Wi-Fi

const char* host = "192.168.1.104";
//const char* host = "127.0.0.1";

const byte rxPin = 4;  // Pinos de conexão Laser >> NodeMCU
const byte txPin = 5;
SoftwareSerial LRF_Port (rxPin, txPin); // Função que realiza a conexão serial Laser >> NodeMCU

void setup() {
  Serial.begin(115200); // Iniciar porta serial
  LRF_Port.begin(19200); // Iniciar serial L >> N

  // Conexão Wi-Fi
  Serial.println(); //PULA UMA LINHA NA JANELA SERIAL
  Serial.println(); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectando a ");
  Serial.print(ssid); //ESCREVE O NOME DA REDE NA SERIAL

  WiFi.begin(ssid, password); //Iniciar conexão Wi-Fi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500); //INTERVALO DE 500 MILISEGUNDOS
    Serial.print("."); //ESCREVE O CARACTER NA SERIAL
  }

  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectado a rede sem fio\n ");
  Serial.println("Fimereço IP: ");
  Serial.println(WiFi.localIP()); //ESCREVE O NOME DA REDE NA SERIAL

}

void loop() {
  String Measure;
  int i = 0;
  int k = 0;

  for (k = 0; k < 12; k++) {
    for (i = 0; i < 6; i++) {

      LRF_Port.write("D");
      Measure = LRF_Port.readStringUntil(13);
      Serial.print("Distancia ");
      Serial.print(Measure);
      Measure.remove(0, 4);
      Measure.remove(1, 1);
      Measure.remove(4, 1);
      //Measure = Measure.substring(0,Measure.length()-4) + "," + Measure.substring(Measure.length()-4);
      Serial.println();
      Serial.print(Measure);
      Serial.println();
      char char1[20];
      float fMeasure;
      Measure.toCharArray(char1, Measure.length() + 1);
      fMeasure = atof(char1);
      Serial.println(fMeasure, 4);


      if (i > 0) {
        /*
          LRF_Port.write("D");
          Measure = LRF_Port.readStringUntil(13);
          Serial.print("Distancia ");
          Serial.print(Measure);
          Measure.remove(0, 4);
          Measure.remove(5, 2);
          Serial.print(Measure);
          Serial.println();
        */

        // Conexão cliente
        WiFiClient client;

        if (client.connect(host, 80)) {
          Serial.println("Conectado");
          Serial.println();
        }
        else {
          Serial.println("Falha na conexão");
          Serial.println();
        }
        switch (k) {
          case 0:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=") + Measure + ("&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 1:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=") + Measure + ("&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 2:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=") + Measure + ("&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 3:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=") + Measure + ("&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 4:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=") + Measure + ("&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 5:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=") + Measure + ("&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 6:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=") + Measure + ("&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 7:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=") + Measure + ("&P_8=&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 8:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=") + Measure + ("&P_9=&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 9:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=") + Measure + ("&P_10=&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 10:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=") + Measure + ("&P_11=&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
          case 11:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=") + Measure + ("&Fim=") +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
            case 12:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_screw_rt.php?Reference=&P_1=&P_2=&P_3=&P_4=&P_5=&P_6=&P_7=&P_8=&P_9=&P_10=&P_11=&Fim=") + Measure +
                         " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n");

            while (client.connected()) {
              if (client.available()) {
                String line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
        }

      }
    }
    delay(8000);
  }
}
