#include "AbstractProductA.h"
#include "AbstractProductB.h"
#include "AbstractFactory.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"

void UsePattern(AbstractFactory *pFactory) {
	AbstractProductA *pA = pFactory->CreateProductA()  ;
	AbstractProductB *pB = pFactory->CreateProductB() ;

	pA->ProductA() ;
	pB->ProductB() ;

	delete pA ;
	delete pB ;
}

int main() {
	AbstractFactory *pFactory = new ConcreteFactory2{} ;
	UsePattern(pFactory) ;
	delete pFactory ;
}
