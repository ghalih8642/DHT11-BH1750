#include <Wire.h>
#include <BH1750.h>
 
 
BH1750 lightMeter(0x23);
 
 
void setup(){
  Wire.begin();
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Running...");
}
 
 
void loop() {
  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}
