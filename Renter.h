#ifndef __RENTER_H_
#define __RENTER_H_
#include <string>
#include <iostream>
class Renter 
{
    std::string renter;
    std::string renter_dl;
    std::string renter_phone;
    public:
    void details(std::string _renter, std::string _renter_dl, std::string _renter_p);
    std::string r_to_string();
    std::string print_details();
    std::string get_renter();
    std::string get_dl();
    std::string get_phone();
};
#endif
