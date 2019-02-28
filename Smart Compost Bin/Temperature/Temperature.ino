#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

int minTemp = 31;
int maxTemp = 32;
int temperature;
 
// Data wire is plugged into pin 5 (was 2) on the Arduino
#define ONE_WIRE_BUS 5  // changed from 2
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(1200);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

lcd.begin(16, 2);              // start the library
lcd.setCursor(0,0);
}
 
 
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
 
  //Serial.print("Temperature is: ");
  
 lcd.clear();
 lcd.print(sensors.getTempCByIndex(0));
 lcd.scrollDisplayLeft();
  
  //Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
     temperature = sensors.getTempCByIndex(0);         
     Serial.print("*** Temp is ***  "); 
     Serial.println(temperature);
     //Serial.print(minTemp);
     
     if (temperature < minTemp)
      { Serial.print("Temperature is too low. Turn heater on ");
       Serial.println(temperature);
      }

      if (temperature >= minTemp)
      { Serial.print(">>> Heater is on >>>  ");
       Serial.println(temperature);
      }

      if (temperature >= maxTemp)
      
      { Serial.print("Temperature is too High. Turn heater off ");
        Serial.println(temperature);
      }
      
    delay(1000);
}
