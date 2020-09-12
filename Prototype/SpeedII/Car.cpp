#include "Car.h"


void Car::Update() {
	std::cout << '[' << GetColor() << GetName() << "]\n"
		<< "\tAnimation:" << GetAnimation() << '\n' ;

	if(m_Dist(m_Engine) && GetColor() == "Red") {
		std::cout
			<< "\tIncrease speed temporarily:"
			<< GetSpeed() * m_SpeedFactor
			<< '\n' ;
	}else{
		std::cout << "\tSpeed:" << GetSpeed() << '\n';
	}

	
	std::cout << "\tHitPoints:" << GetHitPoints() << '\n'
		<< "\tPosition:" << GetPosition() << '\n' ;
}

VehiclePtr Car::Clone() {
	std::cout << "Cloning->" << GetName() << '\n' ;
	return std::shared_ptr<Vehicle>{new Car{*this}} ;
}
