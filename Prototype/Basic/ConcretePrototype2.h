#pragma once
#include "Prototype.h"
class ConcretePrototype2 :
	public Prototype
{

public:
	Prototype* Clone() override;
};

