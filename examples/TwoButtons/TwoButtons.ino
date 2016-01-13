/*
 This is a sample sketch to show how to use the ButtonController library
 to detect click events on 2 buttons in parallel. 
 
 Setup a test circuit:
 * Connect a pushbutton to pin A1 (ButtonPin) and ground.
 * Connect a pushbutton to pin A2 (ButtonPin) and ground.
 * The Serial interface is used for output the detected button events.
 
 The Sketch shows how to setup the library and bind 2 buttons to their functions.
 In the loop function the ButtonController.processing functions have to be called as often as you like.
 */

/* Sample output:

Starting TwoButtons...
Button 1 click.
Button 2 click.
Button 1 doubleclick.
Button 2 doubleclick.
Button 1 longPress start
Button 1 longPress...
Button 1 longPress...
Button 1 longPress...
Button 1 longPress stop
Button 2 longPress start
Button 2 longPress...
Button 2 longPress...
Button 2 longPress stop

*/

#include "ButtonController.h"

// Create a new Button's.  
Button button1;
Button button2;


// setup code here, to run once:
void setup() {

  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);

  // Setup the Serial port. see http://arduino.cc/en/Serial/IfSerial
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Starting TwoButtons...");

} // setup


// main code here, to run repeatedly: 
void loop() {
  // keep watching the push buttons:
  ButtonController::processing(&button1,A1,click1,doubleclick1,longPressStart1,longPressStop1,longPress1);
  ButtonController::processing(&button2,A2,click2,doubleclick2,longPressStart2,longPressStop2,longPress2);
  // May use NULL functions. For example:
  // ButtonController.processing(button2,A2,click2,NULL,NULL,NULL,NULL);
   
  

  // You can implement other code in here or just wait a while 
  delay(10);
} // loop


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
void click1() {
  Serial.println("Button 1 click.");
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");
} // longPressStart1


// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
  Serial.println("Button 1 longPress...");
} // longPress1


// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
} // longPressStop1


// ... and the same for button 2:

void click2() {
  Serial.println("Button 2 click.");
} // click2


void doubleclick2() {
  Serial.println("Button 2 doubleclick.");
} // doubleclick2


void longPressStart2() {
  Serial.println("Button 2 longPress start");
} // longPressStart2


void longPress2() {
  Serial.println("Button 2 longPress...");
} // longPress2

void longPressStop2() {
  Serial.println("Button 2 longPress stop");
} // longPressStop2


// End

