#include "GreenCar.h"

void GreenCar::Update() {
	std::cout << '[' << GetName() << "]\n"
		<< "\tAnimation:" << GetAnimation() << '\n'
		<< "\tSpeed:" << GetSpeed() << '\n'
		<< "\tHitPoints:" << GetHitPoints() << '\n'
		<< "\tPosition:" << GetPosition() << '\n' ;
}

Vehicle* GreenCar::Clone() {
	std::cout << "Cloning->" << GetName() << '\n' ;
	return new GreenCar{*this} ;
}
