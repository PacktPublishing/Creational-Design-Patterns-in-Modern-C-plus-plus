#pragma once
#include "Vehicle.h"
class GreenCar :
    public Vehicle
{
	using Vehicle::Vehicle ;
public:
	void Update() override;
	Vehicle* Clone() override;
};

