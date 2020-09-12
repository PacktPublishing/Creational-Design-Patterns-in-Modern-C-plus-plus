#include "Creator.h"


#include "BlueBus.h"
#include "GreenCar.h"
#include "RedCar.h"
#include "YellowBus.h"

Vehicle* Create(
	std::string_view type, 
	int mSpeed, 
	int mHitPoints, 
	const std::string& mName, 
	std::string_view animFile,
	const Position& mPosition) {
	if(type == "redcar") {
		return new RedCar{mSpeed, mHitPoints, mName, animFile, mPosition} ;
	}else if(type == "greencar") {
		return new GreenCar{mSpeed, mHitPoints, mName, animFile, mPosition} ;
		
	}else if(type == "yellowbus") {
		return new YellowBus{mSpeed, mHitPoints, mName, animFile, mPosition} ;
		
	}else if(type == "bluebus") {
		return new BlueBus{mSpeed, mHitPoints, mName, animFile, mPosition} ;
	}
	return nullptr ;
}
