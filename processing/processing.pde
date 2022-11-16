//Necessary libraries and modules
import processing.serial.*;

//Name communication interface with Arduino
Serial Arduino;

int xpos=90;

//Application and Communication Setup
void setup(){
  size(500, 500); //Size of the application screen
  
  //Attaches communication info to interface
  Arduino = new Serial(this, "COM7", 38400); // Starts the serial communication
  Arduino.bufferUntil('\n'); // Defines delimiter/stop character
}

//Functionality to design and interact with application
void draw(){
  background(230, 100, 200); //Screen background colour
  
  fill(0, 0, 0); // Set the shape fill colour to green
  stroke(255); // Set border colour 
  strokeWeight(2); // Set the width of the border
  rect(100, 100, 120, 50, 10);  // LED ON Button
  rect(280, 100, 120, 50, 10); // LED OFF Button
  rect(100, 40, 300, 50, 10); // Default Button
  
  //Fill buttons with text labels
  fill(255);
  textSize(20);
  text("Set to Default",190, 73);
  text("LED ON",127, 135);
  text("LED OFF", 307, 135);
  
  //Action for when Default is pressed
  if(mousePressed && mouseX>100 && mouseX<400 && mouseY>40 && mouseY<90){
    Arduino.write('a'); // Writes Default data code
  }
  
  //Action for when LED ON is pressed
  if(mousePressed && mouseX>100 && mouseX<220 && mouseY>100 && mouseY<150){
    Arduino.write('b'); // Writes LED On data code
  }
  
  //Action for when LED OFF is pressed
  if(mousePressed && mouseX>280 && mouseX<400 && mouseY>100 && mouseY<150){
    Arduino.write('c'); // Writes LED Off data code
  }
  
  //Servo Control
  if(mouseY > 400) {
    Arduino.write((int)180*(mouseX)/500);
    delay(50);
  }
}
