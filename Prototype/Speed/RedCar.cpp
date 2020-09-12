#include "RedCar.h"


void RedCar::Update() {
	std::cout << '[' << GetName() << "]\n"
		<< "\tAnimation:" << GetAnimation() << '\n' ;

	if(m_Dist(m_Engine)) {
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

Vehicle* RedCar::Clone() {
	std::cout << "Cloning->" << GetName() << '\n' ;
	return new RedCar{*this} ;
}
