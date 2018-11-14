#include "View.h"
//#include<math>
#include<iostream>
#include<string>
#include "Dialogs.h"
View::View()
{
}
View::View(Renter_Site _renter):renter_site{_renter}
{

}
int View::main_menu()
{
    std::string menu  = R"(=====================================
Rental Vehicle Management System
=====================================

Vehicles
------------
(1) Add Vehicle
(2) List all Vehicles
(3) Rent Vehicle
(4) Return Vehicle
Renter
-----------
(5) Add Renter
(6) List all Renters


Utility
----------
(9) Help
(0) Exit

Command? 

 )";

std::string result = Dialogs::input(menu,"");
try{
	if(result=="CANCEL")
		return 0;
	else 
	{
	 int i_result = stoi(result);
	 return i_result;
	}


	//return(result=="CANCEL")? 0 : stoi(result);
	} 
catch(...){
	return -1;
	}
// return result; 
 }
std::string View::help()
{
 Dialogs::message("Adding a vehicle(option 1) requires a year , make , model  and bodystyle. Listing all Vehicles (option 2) displays all information  known about the vehicles, including the identity of their respective renters.Renting a vehicle(option 3) requires a renters name, driver's license number , and phone number.All 3 are arbitary strings.Returning Vehicle requires no additional information.");
    //std:: string s_help = Dialogs::message(help);
return " ";
}
