#include <Wire.h>
#include <BH1750.h>// librarry lux meter

#include <Servo.h>

#define sprayer 4 // pin d4 sparayer
#define kipas 5 // pin d5 kipas
#include <DHT.h> // library DHT11
#include <SoftwareSerial.h>
SoftwareSerial uno(7,8); //d7,d8
DHT dht(2, DHT11); // pin d2, tipe DHT
float kelembaban; //tipe data float variabel untuk kelembaban
byte suhu ; // tipe data byte utk variabel suhu
uint16_t lux;
BH1750 lightMeter(0x23); // a4, a5
Servo myservo;

String kirim;

float data;
float data1;
float data2;
float kosong=0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600); // Serial komunikasi yang digunakan   
  pinMode(sprayer,OUTPUT);// inisialisasi pin mistmaker sebagai output
  digitalWrite(sprayer,HIGH);

  myservo.attach(3);  //pin D3
  myservo.write(180); // awal gerakan pada pertama nyala di posisi 180
 
  pinMode(kipas,OUTPUT);// inisialisasi pin mistmaker sebagai output
  digitalWrite(kipas,HIGH); // inisialisasi pin kipas sebagai output
  dht.begin();
  lightMeter.begin();
  Serial.println("Running...");

  uno.begin(9600); //// inisialisasi komunikasi
}

void loop() {
  Dht();  
  LUX();
  data = suhu ; // tipe data yg dioutputkan float
  data1= kelembaban ;
  data2= lux ;
  kirimmcu();
}

void Dht() {
  // put your main code here, to run repeatedly:
  kelembaban = dht.readHumidity(); // data yang akan dideteksi oleh sensor DHT11
  
  Serial.print("kelembaban: ");
  Serial.println(kelembaban);
   
  suhu = dht.readTemperature(); //

  Serial.print("suhu: ");
  Serial.println(suhu);
  
  //delay(500);

  if(suhu >= 28) // jika suhu lebuh dari sama dengan 28 kipas aktif low (nyala)
  {digitalWrite(kipas,LOW);
  delay(500);} 
 
  if(suhu <= 26) {
  digitalWrite(kipas,HIGH);} // dan sebaliknya
  delay(500);
 
  if(kelembaban <= 80)  // penjelasan sama seperti diatas
  {digitalWrite(sprayer,LOW); //NYALA
  //delay(2000);
  digitalWrite(sprayer,HIGH); 
  delay(1000);}
  
  if (kelembaban >= 85)
  {digitalWrite(sprayer,HIGH);} // MATI
  delay(800);
//  if (suhu < 27)
//  {digitalWrite(sprayer,HIGH);
//  delay(800);}

//  if(kelembaban == 90, suhu == 26)
//  {digitalWrite(sprayer,HIGH);
//  Serial.println("tidak stabil tidak sprayer aktif");
}
void LUX() {
  lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  //delay(500);
  
  if (lux < 6) //jika cahaya kurangdari 30 servo akan bergerak 180 untuk meneutup pintu
  {myservo.write(180);}
  else // dan sebaliknya
  {myservo.write(0);
  //delay(500);}
  delay(4320);}  
}
void kirimmcu(){ //pengiriman data dengan komunikasi 1 arah UART ke node MCU
  kirim= String(kosong) + "#" + String(data) + "#" + String(data1) + "#" + String(data2);
uno.println(kirim);
  }
