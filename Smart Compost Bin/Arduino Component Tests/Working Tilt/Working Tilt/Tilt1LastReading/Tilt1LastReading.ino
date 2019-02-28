// Working Tilt.ino
//  ctrl+shift+m opens serial monitor where the variables can be viewed
//  ctrl+/  Comments out any selected lines of code.

//Constants for where the arduino pins are
#define TILT_PIN 3
#define LED_PIN 13

//Variables
int reading;              // the current reading from the input pin
int lastReading = LOW;    // the last reading from the input pin, whether the Tilt sensor 
                          // is up or down.
int turns = 1;  // counts the number of turns the bin makes
int maxTurns = 3;            
bool turned;              // tells you if the turns has been incremented

// the follow variables are long's because the lastEvent, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastEvent = 0;  // the last time the output pin was toggled
long debounce = 50;           // the debounce time, increase if the output flickers

//Runs once
void setup()
{
  Serial.begin(1200);   //Set baud rate  300  1200  9600  115200
  Serial.println("Start");
  
  pinMode(TILT_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}//End setup

//Runs continuously
void loop()
{
  getTilt();    //Calls the tilt function

  //ctrl+shift+m opens serial monitor where the variables can be viewed
  Serial.println("***************");
  Serial.print("Tilt State: "); Serial.println(reading);
  Serial.print("Bin turned: "); Serial.println(turns);

  //Stops the motor/LED after maxTurns
  //***********************************************************************
  
  if(turns > maxTurns)
  {
    digitalWrite(LED_PIN, LOW);   //LED off
    turns = 0;
  }
  else
  {
    digitalWrite(LED_PIN, HIGH);  //LED on
  }
  //**********************************************************************
}//end loop


//Reads the values of the tiltSensor
void getTilt()
{
  int takeReading;
  reading = digitalRead(TILT_PIN);   //assigns the value of the tilt sensor to a variable

  // If the tilt sensor position changed, due to bounce or pressing...
  if (reading != lastReading)
  {
    // reset the debouncing lastEvent
    lastEvent = millis();
  }

  if ((millis() - lastEvent) > debounce)
  {
    // whatever the position of the Tilt sensor, its been there for a long lastEvent
    // so lets settle on it!
   
    if (reading == LOW)
    {
      takeReading = 1;
//      digitalWrite(LED_PIN, HIGH);  //Turns LED on if tilt sensor up
    }
    else
    {
      takeReading = 0;
//      digitalWrite(LED_PIN, LOW);   //Turns LED off if tilt sensor down

      turned = false;
    }
  }

  // Save the last reading so we keep a running tally
  lastReading = reading;

  //Checks if tilt sensor is up and has not been turned
  //*********************************************************
    if (reading == LOW && !turned)
    {
      //Increments turns by 1, and sets turned to true
      turns ++;
      turned = true;
    }
  //**********************************************************

 }//end getTilt
