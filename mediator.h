// Author: Daniel Gonzalez
// Written for 6.302
//
// This library makes interaction with the web interface simpler

#ifndef mediator
#define mediator
#endif

// include types & constants of Wiring core API
#include "WConstants.h"

// library interface description
class Mediator
{
  // user-accessible "public" interface
  public:
    Test(int);
    void flag(void);
    void pack(void);

  // library-accessible "private" interface
  private:
    void init(void);
};

#endif