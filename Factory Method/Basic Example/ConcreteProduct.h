#pragma once
#include "Product.h"
class ConcreteProduct :
	public Product
{

public:
	void Operation() override;
};

