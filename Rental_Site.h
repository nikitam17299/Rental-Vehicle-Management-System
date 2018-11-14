#ifndef __RENTER_SITE_H_
#define __RENTER_SITE_H_
#include <vector>
#include "Vehicle.h"
#include "Renter.h"
class Renter_Site 
{
    std::vector<Vehicle> vehicles;
    std::vector<Renter> renters;
    public:
    void add_vehicle(Vehicle vehicle);
    void rent_vehicle(int v, Renter t);
    void return_vehicle(int vehicle);
    std::vector<Vehicle> return_vehicles();
    void add_renter(Renter temp);
    std::vector<Renter> return_renters();
};
#endif
