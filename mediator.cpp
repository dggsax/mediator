//Author: Daniel Gonzalez
//Editor: Joe Steimeyer
//Written for 6.302
//Edited for programming sanity


#include "Wifi_S08_v3.h"
#include <WString.h>
#include <Arduino.h>

MEDIATOR * MEDIATOR::_instance;

// Constructors and init method
MEDIATOR::MEDIATOR() {
  init(0, false);
}
MEDIATOR::MEDIATOR(bool verboseSerial) {
  init(0, verboseSerial);
}
MEDIATOR::MEDIATOR(int mode) {
  init(mode, false);
}
MEDIATOR::MEDIATOR(int mode, bool verboseSerial) {
  init(mode, verboseSerial);
}







void MEDIATOR::init(int mode, bool verboseSerial) {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  
}

void MEDIATOR::flag() {
}

void MEDIATOR::pack() {
	
}