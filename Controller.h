#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include "View.h"
#include "Rental_Site.h"
#include "Vehicle.h"
#include <iostream>
#include <vector>
class Controller 
{
    Renter_Site renter_site;
   //View view{renter_site};

    public:
  Controller();
 
  void cli();
    
    void execute_cmd(int command);
};
#endif
