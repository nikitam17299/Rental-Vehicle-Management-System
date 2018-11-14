#include "Renter.h"
//#include "dialogs.h"

void Renter::details(std::string _renter, std::string _renter_dl, std::string _renter_p)
{
    renter = _renter;
    renter_dl = _renter_dl;
    renter_phone = _renter_p;
}
std::string Renter::r_to_string()
{
    std::string result = "Rented to "+renter+"("+renter_dl+","+renter_phone+")"+'\n';
    return result;
}

std::string  Renter::print_details()
{
	std:: string s =  ") Renter's Name: "+ get_renter() + ", Drivers License: "+ renter_dl +  ", Phone number: " + renter_phone + "" + '\n';
    return s;
}

std::string Renter::get_renter()
{
    return renter;
}

std::string Renter::get_dl()
{
    return renter_dl;
}

std::string Renter::get_phone()
{
    return renter_phone;
}
