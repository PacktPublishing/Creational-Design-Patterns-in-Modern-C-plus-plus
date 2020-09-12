#pragma once
#include "Prototype.h"
class ConcretePrototype1 :
	public Prototype
{

public:
	Prototype* Clone() override;
};

