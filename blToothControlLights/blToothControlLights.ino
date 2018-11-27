/*
this program controls lights using a bluetooth module for the ETM356U project
to demonstrate the idea of controlling lights remotely
*/

#include <SoftwareSerial.h> //include the library for bluetooth communication
#define LED_PIN 6 //set LED pin

SoftwareSerial EEBlue(4, 3); //RX | TX

void setup() 
{
  Serial.begin(9600);
  EEBlue.begin(9600); //start listen to bluetooth
  Serial.println("Initiate Bluetooth Communication Protocol");

  pinMode(LED_PIN, OUTPUT); //initiate LED pin
  digitalWrite(LED_PIN, LOW); //initiate the LED as off
}

void loop() 
{
  char input = 'u'; //initiate the input variable
  if (EEBlue.available()) //if bluetooth module is enable
  {
    input = EEBlue.read(); //read the input 
    Serial.println(input); //print out the input
    if(input == 'u')
    {
      digitalWrite(LED_PIN, HIGH);
    }
    else if(input == 'd')
    {
      digitalWrite(LED_PIN, LOW);
    }
  }

}
