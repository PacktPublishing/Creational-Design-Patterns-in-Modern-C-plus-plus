#pragma once
#include "AbstractFactory.h"
class ConcreteFactory1 :
	public AbstractFactory
{

public:
	AbstractProductA* CreateProductA() override;
	AbstractProductB* CreateProductB() override;
};

