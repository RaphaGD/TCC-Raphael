//   LRF           Nodemcu
//   VCC-----------VCC 2,8V
//   RX------------D1
//   TX------------D2
//   GND-----------GND

#include <SoftwareSerial.h>

const byte rxPin = 4;  
const byte txPin = 5;
SoftwareSerial LRF_Port (rxPin, txPin);

void setup()
{
 Serial.begin(115200);
 LRF_Port.begin(19200);                            
 delay(100);
}

void loop()
{
 LRF_Port.write("O");                             
 //delay(100);
 Serial.print("Ligar ");
 Serial.print(LRF_Port.readStringUntil(13));
 Serial.println();

 LRF_Port.write("D");                              
 //delay(500);
 //Serial.print("Distancia ");
 Serial.print(LRF_Port.readStringUntil(13));
 Serial.println();


 LRF_Port.print("C");                              
 //delay(100);
 Serial.print("Desligar ");
 Serial.print(LRF_Port.readStringUntil(13));
 Serial.println();

 LRF_Port.print("S");                             
 //delay(100);
 Serial.print("Status   ");
 Serial.print(LRF_Port.readStringUntil(13));
 Serial.println();  Serial.println();

 //delay(1000);
}
