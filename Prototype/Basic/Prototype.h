#pragma once
class Prototype
{
public:
	virtual Prototype * Clone() = 0 ;
	virtual ~Prototype() = default ;
};

