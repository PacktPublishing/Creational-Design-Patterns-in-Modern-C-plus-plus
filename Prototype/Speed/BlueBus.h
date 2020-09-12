#pragma once
#include <random>

#include "Vehicle.h"
class BlueBus :
    public Vehicle
{
	using Vehicle::Vehicle ;
	std::default_random_engine m_Engine{500} ;
	std::bernoulli_distribution m_Dist{.5} ;
public:
	void Update() override;
	Vehicle* Clone() override;
};

