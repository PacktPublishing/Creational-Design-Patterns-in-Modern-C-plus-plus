#include "GameManager.h"

#include <thread>
#include "Creator.h"
#include "RedCar.h"
#include "Vehicle.h"

void GameManager::Run() {
	m_Vehicles.push_back(Create("redcar", 30, 10, "RedCar", "red.anim", {0, 0})) ;
	m_Vehicles.push_back(Create("greencar", 30, 15, "GreenCar", "green.anim", {100, 0})) ;
	m_Vehicles.push_back(Create("yellowbus", 25, 20, "YellowBus", "ybus.anim", {100, 200})) ;
	m_Vehicles.push_back(Create("bluebus", 25, 25, "BlueBus", "bbus.anim", {200, 200})) ;
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

GameManager::~GameManager() {
	for(auto vehicle:m_Vehicles) {
		delete vehicle ;
	}
}
