#pragma once
#include <vector>

class Vehicle ;
class GameManager
{
	std::vector<Vehicle*> m_Vehicles{} ;
public:
	void Run() ;
	~GameManager();
};

