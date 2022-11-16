#include <SoftwareSerial.h>
#include <Servo.h>

/*
This file contains the code to be uploaded to the arduino microcontroller. 
It sets up bluetooth communication and communicates with the processing
application to send data to be displayed and to allow the application 
to control the Arduino outputs.

Data Codes:
200: All Off
201: Led Off
202: Led On
*/

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth

// Pin numbers of outputs connected to the Arduino
int led = 13;
Servo servo;

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

  servo.attach(9);
  servo.write(90);

  //setup bluetooth serial communication
  Serial.begin(9600);
  mySerial.begin(9600); // For Bluetooth
}

void loop() 
{
  /*//Check for serial data availability
  if(Serial.available() > 0)
  {
    data = Serial.read(); //Read serial port data and store it in data variable
  }

  //Return everything to default state
  if(data == 'a')
  {
    Serial.println("Set to default");
    setDefault();
    //delay(500);      
  }

  //Turn the led off
  if(data == 'c')
  {
    Serial.println("LED off");
    digitalWrite(led, LOW);
    //delay(500);            
  }

  //Turn the led on
  if(data == 'b')
  {
    Serial.println("LED on");
    digitalWrite(led, HIGH);
    //delay(500);
  }*/
  


boolean isValidInput; 
do {  while ( !mySerial.available() ) ; // LOOP...

  data = mySerial.read(); // Execute the option based on the character recieved

  //Serial.print(data); // Print the character received to the IDE serial monitor

  switch ( data ) {

    case 'a': // You've entered a

      // Do the code you need when 'a' is received.....
      mySerial.println( "You've entered an 'a'" );
      mySerial.println("Set to default");
      setDefault();

      isValidInput = true;

      break;

    case 'b': // You've entered b

      // Do the code you need when 'a' is received.....
      mySerial.println("LED on");
      digitalWrite(led, HIGH);

      isValidInput = true;

      break;

    case 'c':
      mySerial.println("LED off");
      digitalWrite(led, LOW);

      break;

    default:

      // Do the code you need when any other character is received.....

      //mySerial.println( "Error" );

      if(0<=(int)data<=180)
      {
        servo.write((int)data);
        mySerial.print((int)data);
        delay(15);            
      } 
      isValidInput = false;

      break;

    }

} while ( isValidInput == true ); // Repeat the loop
    
}


//This function resets everything to its default state
void setDefault()
{
  digitalWrite(led, LOW);
}

