// -----
// ButtonControl.cpp - Library for detecting button clicks, doubleclicks and long press pattern on a single button.
// This class is implemented for use with the Arduino environment.
// -----

#include "ButtonController.h"

void ButtonController::processing(struct Button *button,unsigned char pin,CallbackFunction clickFunc,CallbackFunction doubleClickFunc,CallbackFunction longPressStartFunc,CallbackFunction longPressStopFunc,CallbackFunction duringLongPressFunc)
{
  // Detect the input information 
  int buttonLevel = digitalRead(pin); // current button signal.
  unsigned long now = millis(); // current (relative) time in msecs.

  // Implementation of the state machine
  if (button->state == 0) { // waiting for menu pin being pressed.
    if (buttonLevel == LOW) {
      button->state = 1; // step to state 1
      button->startTime = now; // remember starting time
    } 

  } else if (button->state == 1) { // waiting for menu pin being released.

    if ((buttonLevel == HIGH) && (now < button->startTime + buttonDebounceTicks)) {
      // button was released to quickly so I assume some debouncing.
      // go back to state 0 without calling a function.
      button->state = 0;

    } else if (buttonLevel == HIGH) {
      button->state = 2; // step to state 2

    } else if ((buttonLevel == LOW) && (now > button->startTime + buttonPressTicks)) {
      //_isLongPressed = true;  // Keep track of long press state      
    if (longPressStartFunc) longPressStartFunc();
    if (duringLongPressFunc) duringLongPressFunc();
      button->state = 6; // step to state 6
      
    } else {
      // wait. Stay in this state.
    } 

  } else if (button->state == 2) { // waiting for menu pin being pressed the second time or timeout.
    if (now > button->startTime + buttonClickTicks) {
      // this was only a single short click
      if (clickFunc) clickFunc();
      button->state = 0; // restart.

    } else if (buttonLevel == LOW) {
      button->state = 3; // step to state 3
    } 

  } else if (button->state == 3) { // waiting for menu pin being released finally.
    if (buttonLevel == HIGH) {
      // this was a 2 click sequence.
      if (doubleClickFunc) doubleClickFunc();
      button->state = 0; // restart.
    } 

  } else if (button->state == 6) { // waiting for menu pin being release after long press.
    if (buttonLevel == HIGH) {
    // _isLongPressed = false;  // Keep track of long press state
    if(longPressStopFunc) longPressStopFunc();
      button->state = 0; // restart.
    } else {
    // button is being long pressed
    //_isLongPressed = true; // Keep track of long press state
    if (duringLongPressFunc) duringLongPressFunc();
    } 

  }
}


