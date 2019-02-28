#define TILT_PIN 3
#define LED_PIN 13
int counter;

void setup(){
  pinMode(TILT_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  //Test
  Serial.begin(9600);
}

void loop(){
  if (digitalRead(TILT_PIN) == LOW){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("ON");
    counter++;
  }
  else{
    digitalWrite(LED_PIN, LOW);
    Serial.println("OFF");
  }

  Serial.println(counter);
}
