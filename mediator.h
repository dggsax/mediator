// Author: Daniel Gonzalez
// Written for 6.302
//
// This library makes interaction with the web interface simpler

#ifndef mediator
#define mediator

// Define the global variables for values that will be communicated back and forth between teensy and website
extern float Kp;
extern float Kd;
extern float Kbemf;
extern float Ku;
extern float Ki;
extern float directV;
extern float desiredV;


// include types & constants of Wiring core API
#include <WString.h>
#include "WConstants.h"

// library interface description
class MEDIATOR {
	// user-accessible "public" interface
	public:
  		MEDIATOR();
    	MEDIATOR(int baud);
    	// Test(int);
    	// void flag(void);
    	// void pack(void);
    	void setup(int deltaT, int transferDt);
    	void pack(float a, float b, float c, float d);
    	void restart(String config_message);

  	// library-accessible "private" interface
  	private:
  		// Make MEDIATOR a static member of the class (apparently necessary)
  		static MEDIATOR * _instance;

	    void init(int baud);
	    void initloop();
	    void processString(String inputString);
	    void serialEvent();
};

#endif