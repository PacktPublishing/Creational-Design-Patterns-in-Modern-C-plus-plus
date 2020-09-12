#pragma once
#include <random>

#include "Vehicle.h"
class Car :
    public Vehicle
{
	using Vehicle::Vehicle ;
	float m_SpeedFactor{1.5f} ;
	std::default_random_engine m_Engine{100} ;
	std::bernoulli_distribution m_Dist{.5} ; 
public:
	void SetSpeedFactory(float factor) {
		m_SpeedFactor = factor ;
	}
	void Update() override;
	VehiclePtr Clone() override;
	
};

