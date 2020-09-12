#include "ConcreteBuilder.h"
#include <iostream>
#include "product.h" 
ConcreteBuilder::ConcreteBuilder() {
	std::cout << "[ConcreteBuilder] Created\n" ;
}

void ConcreteBuilder::BuildPart() {
	std::cout << "[ConcreteBuilder] Building...\n" ;
	std::cout << "\t Part A\n" ;
	std::cout << "\t Part B\n" ;
	std::cout << "\t Part C\n" ;

	product = new Product{} ;
}

Product* ConcreteBuilder::GetResult() {
	std::cout << "[ConcreteBuilder] Returning result\n" ;
	return product ;
}
