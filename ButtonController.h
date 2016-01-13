
#ifndef ButtonController_h
#define ButtonController_h

#include "Arduino.h"

// ----- Callback function types -----

extern "C" {
  typedef void (*CallbackFunction)(void);
}

struct Button { 
  unsigned char state = 0;
  unsigned long startTime; // will be set in state 1
};

 
class ButtonController
{
 public: 
 static void processing(Button button,unsigned char pin,CallbackFunction clickFunc,CallbackFunction doubleClickFunc,CallbackFunction longPressStartFunc,CallbackFunction longPressStopFunc,CallbackFunction duringLongPressFunc);
 
 private:
 static const unsigned int buttonClickTicks = 500; // number of ticks that have to pass by before a click is detected
 static const unsigned int buttonPressTicks = 1000; // number of ticks that have to pass by before a long button press is detected
 static const unsigned int buttonDebounceTicks = 50; // number of ticks for debounce times.

};

#endif


