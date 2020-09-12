#pragma once
class AbstractProductA ;
class AbstractProductB ;
class AbstractFactory
{
public:
	virtual AbstractProductA * CreateProductA() = 0 ;
	virtual AbstractProductB * CreateProductB() = 0 ;
	virtual ~AbstractFactory()=default ;
};

