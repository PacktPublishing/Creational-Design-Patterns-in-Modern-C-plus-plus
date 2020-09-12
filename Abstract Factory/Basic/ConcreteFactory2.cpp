#include "ConcreteFactory2.h"
#include "Set2.h"

AbstractProductA* ConcreteFactory2::CreateProductA() {
	return new ProductA2{} ;
}

AbstractProductB* ConcreteFactory2::CreateProductB() {
	return new ProductB2{} ;
}
