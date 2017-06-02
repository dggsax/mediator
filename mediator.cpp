//Author: Daniel Gonzalez
//Editor: Joe Steimeyer
//Written for 6.302
//Edited for programming sanity


#include "mediator.h"
#include <WString.h>
#include <Arduino.h>

MEDIATOR * MEDIATOR::_instance;

// Things
// NOTE: With windows systems ~or~ Uno's, first_time actually has to start out as true...
bool first_time = false;
char buf[60];  // Build the buffer for us to put information to send to the webpage/{whatever we'll call it}.
int loopCounter;
int numSkip;  // Number of loops to skip between host updates.

// Define the global variables for values that will be communicated back and forth between teensy and website
float Kp;
float Kd;
float Kbemf;
float Ku;
float Ki;
float directV;
float desiredV;

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

// Automatically runs once the library is initiatied. Sets up the serial and get's things going
void MEDIATOR::initloop() {
	loopCounter = 0;
	// headroom = deltaT;
	// NOTE: Headroom might be useful in the future, but right now it's of no benefit to us
	// users in the future might depend on it for calculation lag time, so we'll have to 
	// reconsider it eventually...
}

void MEDIATOR::setup(int deltaT, int transferDt) {
	// Number of loops between transfers to host.
	numSkip = max(int((transferDt+100)/deltaT),1); 
}

void MEDIATOR::restart(String config_message) {
	if (first_time) {
	    while(Serial.available() > 0) Serial.read(); // Clear out the serial buffer
	    Serial.println(config_message);  // Send the configuration files.
	    while (! Serial.available()) {}  // Wait for serial return.
	    while(Serial.available() > 0) Serial.read(); // Clear out the serial buffer
	    initloop();
	    first_time = false;
	} else {
	    serialEvent();
	}
}

void MEDIATOR::serialEvent() {
  String inputString = ""; 
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    // if the incoming character is a newline, ready to process.
    if (inChar == '\n') {
      processString(inputString);
      inputString = "";
      break;
    }
  }
}

void MEDIATOR::pack(float a, float b, float c, float d) {
	if (loopCounter == numSkip) {
		// Start Byte.
		buf[0] = byte(0);
		int n = 1; 
		memcpy(&buf[n],&a,sizeof(a));
		n += sizeof(a);
		memcpy(&buf[n],&b,sizeof(b));
		n += sizeof(b);
		memcpy(&buf[n],&c,sizeof(c));
		n += sizeof(c);
		memcpy(&buf[n],&d,sizeof(d));
		n += sizeof(d);
		// Stop byte (255 otherwise unused).
		buf[n] = byte(255);

		// Send the buffer to the Serial
		Serial.write(buf,18);

		loopCounter = 0;

	} else loopCounter += 1;
}

void MEDIATOR::processString(String inputString) {
	char St = inputString.charAt(0);
	inputString.remove(0,1);
	float val = inputString.toFloat();
	switch (St) {
		case 'P': 
			Kp = val;
			break;
		case 'D':
			Kd = val;
			break;  
		case 'E':
			Kbemf = val;
			break;
		case 'U':
			Ku = val;
			break;
		case 'I':
			Ki = val;
			break;  
		case 'O':  
			directV = val;
			break;
		case 'A':
			desiredV = val;
			break;
		case '~':
			first_time = true;
			break;
		default:
		break;
	}
}