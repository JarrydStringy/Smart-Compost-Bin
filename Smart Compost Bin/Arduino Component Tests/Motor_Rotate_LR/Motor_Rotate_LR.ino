#define MOTOR_L 8
#define MOTOR_R 9

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  digitalWrite(MOTOR_L, HIGH);
  Serial.println("Turn Left");
  delay(1000);

  digitalWrite(MOTOR_R, HIGH);
  Serial.println("Stop");
  delay(1000);

  digitalWrite(MOTOR_L, LOW);
  Serial.println("Turn Right");
  delay(1000);

  digitalWrite(MOTOR_R, LOW);
  Serial.println("Stop");
  delay(1000);
}
