#include "Bus.h"
#include "Car.h"
#include "GameManager.h"
#include "VehiclePrototypes.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ) ;
	VehiclePrototypes::RegisterPrototype("car", std::make_shared<Car>()) ;
	VehiclePrototypes::RegisterPrototype("bus", std::make_shared<Bus>()) ;
	for(const auto &prototype: VehiclePrototypes::GetKeys()) { 
		std::cout << prototype << '\n' ;
	}
	GameManager mgr ;
	mgr.Run() ;
}
