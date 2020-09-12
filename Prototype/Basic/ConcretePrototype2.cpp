#include "ConcretePrototype2.h"
#include <iostream>

Prototype* ConcretePrototype2::Clone() {
	std::cout << "[ConcretePrototype2] Cloning...\n" ;
	
	return new ConcretePrototype2{*this} ;
}
