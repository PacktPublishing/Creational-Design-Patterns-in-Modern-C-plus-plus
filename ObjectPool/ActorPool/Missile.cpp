#include "Missile.h"

#include <iostream>


Missile::Missile() {
	std::cout << "++++ Missile Created\n" ;
}

Missile::~Missile() {
	std::cout << "~~~~ Missile Destroyed\n" ;
}

void Missile::Update() {
	std::cout << "-> " ;
}
