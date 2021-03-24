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

  for(k = 0; k < 6; k++){
    for(i = 0; i < 11; i++){
      
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
        Measure.toCharArray(char1, Measure.length() +1);
        fMeasure = atof(char1);
        Serial.println(fMeasure, 4);
        
        
      if (i > 0){
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
        switch (k){
          case 0:
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_rt.php?Reference=") + Measure + ("&Object_1=&Object_2=&Object_3=&Object_4=&Fim=") + 
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
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_rt.php?Reference=&Object_1=") + Measure + ("&Object_2=&Object_3=&Object_4=&Fim=") + 
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
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_rt.php?Reference=&Object_1=&Object_2=") + Measure + ("&Object_3=&Object_4=&Fim=") + 
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
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_rt.php?Reference=&Object_1=&Object_2=&Object_3=") + Measure + ("&Object_4=&Fim=") + 
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
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_rt.php?Reference=&Object_1=&Object_2=&Object_3=&Object_4=") + Measure + ("&Fim=") + 
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
            client.print(String ("GET http://127.0.0.1/nodemcu/salvar_ensaio_fixo_rt.php?Reference=&Object_1=&Object_2=&Object_3=&Object_4=&Fim=") + Measure +
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
    delay(5000);
  }
}
 
