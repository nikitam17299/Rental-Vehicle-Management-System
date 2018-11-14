#ifndef __VIEW_H_
#define __VIEW_H_
#include <vector>
#include "Rental_Site.h"
class View 
{
    Renter_Site renter_site;//_rental_site
    public:
    View(Renter_Site _renter);//rental_site
   View();
    int main_menu();
    std::string help();
};
#endif
