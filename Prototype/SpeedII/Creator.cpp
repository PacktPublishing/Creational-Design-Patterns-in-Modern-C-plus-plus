#include "Creator.h"


#include "Bus.h"
#include "Car.h"

Vehicle* Create(
	std::string_view type, 
	int mSpeed, 
	int mHitPoints, 
	const std::string& mName, 
	std::string_view animFile,
	const Position& mPosition) {
	if(type == "redcar") {
		return new Car{mSpeed, mHitPoints, mName, animFile, mPosition, "Red"} ;
	}else if(type == "greencar") {
		return new Car{mSpeed, mHitPoints, mName, animFile, mPosition, "Green"} ;
		
	}else if(type == "yellowbus") {
		return new Bus{mSpeed, mHitPoints, mName, animFile, mPosition, "Yellow"} ;
		
	}else if(type == "bluebus") {
		return new Bus{mSpeed, mHitPoints, mName, animFile, mPosition, "Blue"} ;
	}
	return nullptr ;
}
