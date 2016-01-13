Arduino ButtonController Library
===

This Arduino libary is improving the usage of a singe button for input.
It shows how to use an digital input pin with a single pushbutton attached
for detecting some of the typical button press events like single clicks, double clicks and long-time pressing.
This enables you to reuse the same button for multiple functions and lowers the hardware invests.

####Support features:
 - `click()`
 - `doubleClick()`
 - `longPressStart()`
 - `longPress()`
 - `longPressStop()`

####Distinctive features:
 - **Debounce** system based on function millis (**not used delay**)
 - It occupies very little memory in the microcontroller (**5 byte per button**)
 - Not create new objects in memory
 - Not use hardware interrupts

####Limitations:
 - Use only **`INPUT_PULLUP`** button connection type (connect button to ground -GND )


## Simple usage

```C++
#include "ButtonController.h"

// Create new Buttons structures.  
Button button1;
Button button2;

void setup() {
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
} 

void loop() {
  ButtonController::processing(button1,A1,click,doubleClick,longPressStart,longPressStop,longPress);  
                                             // A1 - id of PIN where button1 connected
                                             // "click" - name of function for click event
                                             // "doubleClick" - name of function for doubleClick event 
                                             // and so on ...
  
  ButtonController::processing(button2,A2,clickFunction2,NULL,NULL,NULL,NULL);   
                                             // A2 - id of PIN where button2 connected
                                             // clickFunction2 - name of function for click event for button2
                                             // You may write NULL for unused functions
  
  // You can implement other code in here or just wait a while 
} 

void click() {
  // Your code for click event here for button 1
}

void doubleClick() {
  // Your code for doubleClick event here for button 1
}

void longPressStart() {
  // Your code for longPressStart event here for button 1
}

void longPress() {
  // Your code for longPress event here for button 1
}

void longPressStop() {
  // Your code for longPressStop event here for button 1
}

void clickFunction2() {
  // Your code for click event here for button 2
} 
```
