#pragma once
#include "Creator.h"
class ConcreteCreator :
	public Creator
{

public:
	Product* Create() override;
};

