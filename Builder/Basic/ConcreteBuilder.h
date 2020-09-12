#pragma once
#include "Builder.h"
class Product ;
class ConcreteBuilder :
	public Builder
{
	Product *product ;
public:
	ConcreteBuilder() ;
	void BuildPart() override;
	Product * GetResult() ;
};

