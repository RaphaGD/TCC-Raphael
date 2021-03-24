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
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP()); //ESCREVE O NOME DA REDE NA SERIAL
  
}

void loop() {
/*
  Códigos módulo Laser
  LRF_Port.write("O");                             
  //delay(100);
  Serial.print("Ligar ");
  Serial.print(LRF_Port.readStringUntil(13));
  Serial.println();
*/

  /*
  LRF_Port.write("D");                              
  //delay(500);
  String Measure = LRF_Port.readStringUntil(13);
  Serial.print("Distancia ");
  Serial.print(Measure);
  Measure.remove(0, 4);
  Measure.remove(6);
  String teste = Measure.substring(Measure.indexOf(' ') + 1);
  Serial.println(teste);
  Serial.println();
  Serial.print(Measure);  
  Serial.println();
  */
  String Measure;
  float TOT = 0;
  int i = 0;
  float Average = 0;
  
  for(i = 0; i = 10; i++){
    if (i > 0){
      LRF_Port.write("D");
      Measure = LRF_Port.readStringUntil(13);
      Serial.print("Distancia ");
      Serial.print(Measure);
      Measure.remove(0, 3);
      Measure.remove(6);
      Serial.print(Measure);  
      Serial.println();
      char Measure_temp[sizeof(Measure)];
      Measure.toCharArray(Measure_temp, sizeof(Measure));
      
      float M = atof(Measure);
      
      TOT += Measure;
    }
  }
  
  Average = TOT/i;
/*
 * 
 * Substring PESQUISAR
  LRF_Port.print("C");                              
  //delay(100);
   Serial.print("Desligar ");
  Serial.print(LRF_Port.readStringUntil(13));
  Serial.println();
  
  LRF_Port.print("S");                             
  delay(100);
  Serial.print("Status   ");
  Serial.print(LRF_Port.readStringUntil(13));
  Serial.println();  Serial.println();
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
  
  // Gerando URL
  /*String //url = "/nodemcu/salvar.php?Measure=2&Average=2&SD=3";
         //url = "/nodemcu/salvar.php?";
         //url += "Measure=";
         //url += 1;
         //url += "&Average=";
         //url += 1;
         //url += "&SD=";
         //url += 1;
         
  //Serial.print("Requisitando URL: ");
  //Serial.println(url);
*/
  client.print(String ("GET http://127.0.0.1/nodemcu/salvar.php?Measure=") + Measure + ("&Average=") + Average + ("&SD=3") + 
              " HTTP/1.1\r\n" + 
              "Host: " + host + "\r\n" + 
              "Connection: close\r\n\r\n");   
                    
  Serial.print("1");
  
  while (client.connected()) {
    Serial.print("2");
    if (client.available()) {
       Serial.print("3");
       String line = client.readStringUntil('\n');
       Serial.println(line);
    }
  }
  Serial.print("4");
  
}
