void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(A0));  
  delay(100);
}
