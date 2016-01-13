/*
 This is a sample sketch to show how to use the ButtonController library
 to detect click event.
 
 Setup a test circuit:
 * Connect a pushbutton to pin A1 (ButtonPin) and ground.
 * Connect a pushbutton to pin 13 to LED.
 */


#include "ButtonController.h"

// Create a new Button.  
Button button;

// setup code here, to run once:
void setup() {
  pinMode(A1,INPUT_PULLUP);
  pinMode(13,OUTPUT);
} 

// main code here, to run repeatedly: 
void loop() {
  // keep watching the push buttons:
  ButtonController::processing(&button,A1,clickFunction,NULL,NULL,NULL,NULL);  
  // May use ather functions. For example:
  // ButtonController::processing(button1,A1,click1,doubleclick1,longPressStart1,longPressStop1,longPress1);
   
  
  // You can implement other code in here or just wait a while 
  delay(10);
} 


// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
boolean isLedEnable = false;
void clickFunction() {
  isLedEnable=!isLedEnable;
  digitalWrite(13,isLedEnable?HIGH:LOW);
} 


