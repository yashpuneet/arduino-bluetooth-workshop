/*
This file contains the code to be uploaded to the arduino microcontroller. 
It sets up bluetooth communication and communicates with the processing
application to send data to be displayed and to allow the application 
to control the Arduino outputs.

Data Codes:
0: All Off
1: Led Off
2: Led On
*/

// Pin numbers of outputs connected to the Arduino
int led = 13;

// Pin numbers of the inputs connected to the Arduino

// Declaration Variable and Constants used in the code
int ledStatus = 0; //Set the led status to off
int data = 0; //Data Received by the arduino

// This function runs once to setup the board, its outputs and 
// communication methods
void setup() 
{
  //setup led pin and set the default state to off
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  //setup bluetooth serial communication
  Serial.begin(38400);
}

void loop() 
{
  //Check for serial data availability
  if(Serial.available() > 0)
  {
    data = Serial.read(); //Read serial port data and store it in data variable
  }

  //Return everything to default state
  if(data == '0')
  {
    Serial.println("Set to default");
    setDefault();
    delay(500);      
  }

  //Turn the led off
  if(data == '1')
  {
    Serial.println("LED off");
    digitalWrite(led, LOW);
    delay(500);            
  }

  //Turn the led on
  if(data == '2')
  {
    Serial.println("LED on");
    digitalWrite(led, HIGH);
    delay(500);
  }  
}


//This function resets everything to its default state
void setDefault()
{
  digitalWrite(led, LOW);
}
