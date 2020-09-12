#include "SharedObject.h"

#include <iostream>

void SharedObject::MethodA() {
	std::cout << "MethodA\n" ;
}

void SharedObject::MethodB() {
	std::cout << "MethodB\n" ;
}

void SharedObject::Reset() {
	std::cout << "Resetting the state\n" ;
}
