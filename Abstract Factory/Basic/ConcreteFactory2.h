#pragma once
#include "AbstractFactory.h"
class ConcreteFactory2 :
	public AbstractFactory
{

public:
	AbstractProductA* CreateProductA() override;
	AbstractProductB* CreateProductB() override;
};

