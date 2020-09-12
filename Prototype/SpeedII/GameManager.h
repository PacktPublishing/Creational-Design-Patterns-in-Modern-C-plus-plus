#pragma once
#include <vector>

#include "Vehicle.h"

class GameManager
{
	std::vector<VehiclePtr> m_Vehicles{} ;
public:
	void Run() ;
};

