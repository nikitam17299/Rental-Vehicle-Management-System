#include "Rental_Site.h"
//#include<gtkmm.h>
#include"Dialogs.h"
void Renter_Site::add_vehicle(Vehicle vehicle)
{
    vehicles.push_back(vehicle);
}
void Renter_Site::rent_vehicle(int vehicle, Renter r)
{
    if(vehicle<1 && vehicle>vehicles.size())
    {
	    Dialogs::message("Invalid Input");
        return;
    }
    std::string name,renter_dl,phone;
    name= r.get_renter();
    renter_dl=r.get_dl();
    phone = r.get_phone();
    vehicles[vehicle].details(name,renter_dl,phone);
    vehicles[vehicle].turn();
}
void Renter_Site::return_vehicle(int vehicle)
{
    if(vehicle<1 && vehicle>vehicles.size())
    {
	    Dialogs::message("It's Invalid");
            return;
    }
    if(vehicles[vehicle].get_is_rented()==false)
            Dialogs::message("Vehicle is not Rented");
    else
    { 
           vehicles[vehicle].turn();
	   Dialogs::message("Vehicle Returned!");
    }

}
std::vector<Vehicle> Renter_Site::return_vehicles()
{
    return vehicles;
}

void Renter_Site::add_renter(Renter temp)
{
    renters.push_back(temp);
}

std::vector<Renter> Renter_Site::return_renters()
{
    return renters;
}
