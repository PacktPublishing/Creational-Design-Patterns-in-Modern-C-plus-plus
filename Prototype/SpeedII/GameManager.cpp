#include "GameManager.h"

#include <thread>
#include "Creator.h"
#include "Vehicle.h"
#include "VehiclePrototypes.h"
#include "Animation.h"
VehiclePtr GetRedCar() {
	auto vehicle = VehiclePrototypes::GetPrototype("car") ;
	vehicle->SetColor("Red") ;
	vehicle->SetHitPoints(10) ;
	vehicle->SetSpeed(30) ;
	vehicle->SetPosition({0,0}) ;
	Animation anim{"red.anim"} ;
	vehicle->SetAnimationData(anim.GetAnimationData()) ;
	return vehicle ;
}
VehiclePtr GetGreenCar() {
	auto vehicle = VehiclePrototypes::GetPrototype("car") ;
	vehicle->SetColor("Green") ;
	vehicle->SetHitPoints(5) ;
	vehicle->SetSpeed(30) ;
	vehicle->SetPosition({100,0}) ;
	Animation anim{"green.anim"} ;
	vehicle->SetAnimationData(anim.GetAnimationData()) ;
	return vehicle ;
}
VehiclePtr GetYellowBus() {
	auto vehicle = VehiclePrototypes::GetPrototype("bus") ;
	vehicle->SetColor("Yellow") ;
	vehicle->SetHitPoints(20) ;
	vehicle->SetSpeed(25) ;
	vehicle->SetPosition({100,200}) ;
	Animation anim{"ybus.anim"} ;
	vehicle->SetAnimationData(anim.GetAnimationData()) ;
	return vehicle ;
}
VehiclePtr GetBlueBus() {
	auto vehicle = VehiclePrototypes::GetPrototype("bus") ;
	vehicle->SetColor("Blue") ;
	vehicle->SetHitPoints(25) ;
	vehicle->SetSpeed(25) ;
	vehicle->SetPosition({200,200}) ;
	Animation anim{"bbus.anim"} ;
	vehicle->SetAnimationData(anim.GetAnimationData()) ;
	return vehicle ;
}
void GameManager::Run() {
	m_Vehicles.push_back(GetRedCar()) ;
	m_Vehicles.push_back(GetGreenCar()) ;
	m_Vehicles.push_back(GetYellowBus()) ;
	m_Vehicles.push_back(GetBlueBus()) ;
	int count{5} ;
	using namespace std ;
	while(count !=0) {
		std::this_thread::sleep_for(1s) ;
		system("cls") ;
		for(auto vehicle : m_Vehicles) {
			vehicle->Update() ;
		}
		if(count == 2) {
			//m_Vehicles.push_back(Create("redcar",30, 15, "RedCar", "red.anim", {50, 50})) ;
			auto vehicle = m_Vehicles[0]->Clone() ;
			vehicle->SetPosition({50, 50}) ;
			vehicle->SetHitPoints(15) ;
			m_Vehicles.push_back(vehicle) ;
		}
		if(count == 3) {
			//m_Vehicles.push_back(Create("yellowbus",20, 20, "YellowBus", "ybus.anim", {150, 250})) ;
			auto vehicle = m_Vehicles[2]->Clone() ;
			vehicle->SetPosition({150, 250}) ;
			vehicle->SetSpeed(10) ;
			m_Vehicles.push_back(vehicle) ;
		}
		--count ;
	}
}

