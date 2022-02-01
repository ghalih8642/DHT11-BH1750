// https://www.youtube.com/watch?v=1Qndq5OV_XE
#include <DHT.h> // library DHT11

DHT dht(2, DHT11); // pin d4, tipe DHT
#define sprayer 16 // pin d0 sparayer
#define kipas 5 // pin d1 kipas

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Serial komunikasi yang digunakan 
  pinMode(sprayer,OUTPUT);// inisialisasi pin mistmaker sebagai output
  digitalWrite(sprayer,HIGH);
  
  pinMode(kipas,OUTPUT);// inisialisasi pin mistmaker sebagai output
  digitalWrite(kipas,HIGH);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  byte kelembaban = dht.readHumidity(); // data yang akan dideteksi oleh sensor DHT11
  
  Serial.print("kelembaban: ");
  Serial.println(kelembaban);
   {
  if (kelembaban >= 70)
  digitalWrite(sprayer,LOW);
  else if(kelembaban <= 60)
  digitalWrite(sprayer,HIGH);
  }
  byte suhu = dht.readTemperature(); //

  Serial.print("suhu: ");
  Serial.println(suhu);
  
  delay(1000);

  {
  if (suhu >= 32)
  digitalWrite(kipas,LOW);
  else 
  digitalWrite(kipas,HIGH);
  }
 
}
