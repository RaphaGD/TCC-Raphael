#define D1 05 
#define D2 04 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D1, INPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int MED1 = digitalRead(D1);
  int MED2 = digitalRead(D2);
  Serial.println("D2: ");
  Serial.println(MED1);
  Serial.println("D2: ");
  Serial.println(MED2);
  
}
