#pragma once
#include "AbstractProductA.h"
#include <iostream>
#include "AbstractProductB.h"

class ProductA1 : public AbstractProductA {

public:
	void ProductA() override {
		std::cout << "[1] Product A\n" ;
	}
};

class ProductB1 : public AbstractProductB {

public:
	void ProductB() override {
		std::cout << "[1] Product B\n" ;
	}
};
