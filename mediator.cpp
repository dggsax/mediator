//Author: Daniel Gonzalez
//Editor: Joe Steimeyer
//Written for 6.302
//Edited for programming sanity


#include "mediator.h"
#include <WString.h>
#include <Arduino.h>

MEDIATOR * MEDIATOR::_instance;

// Constructors and init method
MEDIATOR::MEDIATOR() {
	init(115200);
}
MEDIATOR::MEDIATOR(int baud) {
	init(baud);
}

// Automatically runs once the library is initiatied. Sets up the serial and get's things going
void MEDIATOR::init(int baud) {
	_instance = this;
	Serial.begin(baud);
	while (!Serial){
		;
	}
}


void MEDIATOR::pack() {
	;
	// char buf[60];  // Build the buffer for us to put information to send to the webpage/{whatever we'll call it}.
}