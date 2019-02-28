//Constants for where the arduino pins are
#define TILT_PIN 3
#define LED_PIN 13

//Variables
int reading;                // the current reading from the input pin
int lastTiltState = LOW;    // the lastTiltState reading from the input pin
int counter;                // finds out how many turns the bin has done
int switchState;            // tells you if the switch is up or down
bool sent;                  // tells you if the counter has been incremented

// the follow variables are long's because the lastEvent, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastEvent = 0;  // the last time the output pin was toggled
long debounce = 50;           // the debounce time, increase if the output flickers


//Runs once
void setup()
{
  Serial.begin(115200);             //A set baud rate
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
  Serial.print("Tilt State: "); Serial.println(switchState);
  Serial.print("Message Sent: "); Serial.println(sent);
  Serial.print("Counter: "); Serial.println(counter);

  //Stops the motor/LED after 3 cycles
  //***********************************************************************
  int cycles = 3;
  if(counter > cycles)
  {
    digitalWrite(LED_PIN, LOW);   //LED off
  }
  else
  {
    digitalWrite(LED_PIN, HIGH);  //LED on
  }
  //**********************************************************************
}//end loop


//Reads the values of the tiltSensor
int getTilt()
{
  int takeReading;
  reading = digitalRead(TILT_PIN);      //assigns the value of the tilt sensor to a variable

  // If the switch changed, due to bounce or pressing...
  if (reading != lastTiltState)
  {
    // reset the debouncing lastEventr
    lastEvent = millis();
  }

  if ((millis() - lastEvent) > debounce)
  {
    // whatever the switch is at, its been there for a long lastEvent
    // so lets settle on it!
    switchState = reading;

    if (switchState == LOW)
    {
      takeReading = 1;
//      digitalWrite(LED_PIN, HIGH);  //Turns LED on if tilt sensor up
    }
    else
    {
      takeReading = 0;
//      digitalWrite(LED_PIN, LOW);   //Turns LED off if tilt sensor down

      //
      sent = false;
    }
  }

  // Save the last reading so we keep a running tally
  lastTiltState = reading;

  //Checks if tilt sensor is up and the message has not been sent
  //*********************************************************
    if (switchState == LOW && !sent)
    {
      //Adds 1 to the counter and sets sent to true
      counter++;
      sent = true;
    }
  //**********************************************************

  return takeReading;
}//end getTilt
