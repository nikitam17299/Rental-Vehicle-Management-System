#ifndef __VEHICLE_H
#define __VEHICLE_H
#include <iostream>
#include "Renter.h"
enum class Body_Style {SEDAN, HATCHBACK, MINIVAN, TRUCK, SUV, CROSSOVER};

class Vehicle : public Renter
{
    std::string make;
    std::string model;
    int year;
    Body_Style body_style;
    bool is_rented;

    public:
    Vehicle (int _year, std::string _make, std::string _model, Body_Style _body_style);
    void turn();
    bool get_is_rented();
    friend std::ostream& operator<<(std::ostream& ost, const Vehicle& v);
};
#endif
