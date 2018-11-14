#include <iostream>
#include "Vehicle.h"
Vehicle::Vehicle(int _year, std::string _make, std::string _model , Body_Style _body_style)  {
    	year=_year;
	make=_make;
	model=_model;
	body_style=_body_style;
	is_rented = false;
};

std::ostream& operator<<(std::ostream& ost, const Vehicle& vehicle)
//std::striing Vehicle::vehicle_to_string(Vehicle vehicle)

{  std::string s;
    std::string b_body_style;
    switch(vehicle.body_style)
    {
        case Body_Style::SEDAN : b_body_style = "SEDAN";
              break;
        case Body_Style::HATCHBACK : b_body_style = "HATCHBACK";
                break;
        case Body_Style::MINIVAN :b_body_style = "MINIVAN";
                break;
        case Body_Style::TRUCK : b_body_style = "TRUCK";
                break;
        case Body_Style::SUV : b_body_style = "SUV";
                break;
        case Body_Style::CROSSOVER : b_body_style = "CROSSOVER";
                break; 
    }
  ost<< vehicle.year<<" "<<vehicle.make<<" "<<vehicle.model<<" "<<b_body_style<<"\n";
    return ost;
}

//std::string vehicle_to_string()
//{ std::string s; 
//  std::


void Vehicle::turn()
{
        if(is_rented == true)
            is_rented = false;
        else
            is_rented = true;
}

bool Vehicle::get_is_rented()
{
    return is_rented;
}
