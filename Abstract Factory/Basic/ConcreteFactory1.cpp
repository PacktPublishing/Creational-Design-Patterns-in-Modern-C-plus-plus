#include "ConcreteFactory1.h"
#include "Set1.h"

AbstractProductA* ConcreteFactory1::CreateProductA() {
	return new ProductA1{} ;
}

AbstractProductB* ConcreteFactory1::CreateProductB() {
	return new ProductB1{} ;
}
