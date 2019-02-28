//Constants for where the arduino pins are used for with 1 being the closest component
#define MOISTURE_1 A0
#define MOISTURE_2 A1
#define TEMP_2 4
#define TEMP_1 5
#define PUMP_2 6
#define PUMP_1 7
#define MOTOR_DOWN 8
#define MOTOR_UP 9
#define FAN 10
#define SERVO 11
#define TILT 13

//Variables
waitTime = 100000;


//Setup runs once
void setup()
{
  Serial.begin(115200);       //A set baud rate to initiate serial communication
  Serial.println("Start");    //Talks to serial        
}//End setup


//Loop runs continuously
void loop()
{
  //Rotate barrell both directions using tilt

  //2 Temperatures
  Temperature();

  //2 Moistures
  Moisture();

 //Delay code for set time
}//end loop


void Temperature(){
  //Measure Temperature
//  digitalWrite(TEMP_1, HIGH);
  //Open servo wing for aeration or heats bin with fan for correct temperature
  //Close servo wing or stops fan
  //Rotate Barrell

  //Measure Temperature again and repeat if still too hot or cold
}


void Moisture(){
  //Measure Moisture

  //Turn on water pump if not enough water or fan and servo if too wet
  //Turn off water pump or fan and servo
  //Rotate Barrell

  //Measure Moisture again and repeat if too dry
}
