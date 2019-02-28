#define MoisturePin A1
#include <LiquidCrystal.h>

int maxWet = 200;
int minWet = 50;

void setup(){
  Serial.begin(1200); 
}

void loop(){
  ReadMoisture();
}

void ReadMoisture(){
    Serial.print("Moisture Sensor Value:");
  
  int reading = analogRead(MoisturePin);
  Serial.println(reading);  
  
  delay(100);
}
