#include "Alien.h"

#include <iostream>

Alien::Alien() {
	std::cout << "++++++ Alien constructed\n" ;
}

Alien::~Alien() {
	std::cout << "~~~~~~ Alien destroyed\n" ;
}

void Alien::Update() {
	std::cout << "@ " ;
}
