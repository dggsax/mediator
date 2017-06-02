// Author: Daniel Gonzalez
// Written for 6.302
//
// This library makes interaction with the web interface simpler

#ifndef mediator
#define mediator
// #endif                                                               

// include types & constants of Wiring core API
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
    void pack();

  // library-accessible "private" interface
  private:
  	// Make MEDIATOR a static member of the class (apparently necessary)
  	static MEDIATOR * _instance;

    void init(int baud);
};

#endif