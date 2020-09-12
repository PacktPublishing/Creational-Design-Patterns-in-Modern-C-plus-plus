#pragma once
#include <iostream>
#include "AbstractProductB.h"
#include "AbstractProductA.h"

class ProductA2 : public AbstractProductA {

public:
	void ProductA() override {
		std::cout << "[2] Product A\n" ;
	}
};

class ProductB2 : public AbstractProductB {

public:
	void ProductB() override {
		std::cout << "[2] Product B\n" ;
	}
};