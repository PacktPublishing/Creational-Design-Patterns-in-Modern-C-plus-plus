#include "ConcretePrototype1.h"
#include <iostream>

Prototype* ConcretePrototype1::Clone() {
	std::cout << "[ConcretePrototype1] Cloning...\n" ;
	return new ConcretePrototype1{*this} ;
}
