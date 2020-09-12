#pragma once
#include "Actor.h"
class Alien :
    public Actor
{
public:
	Alien() ;
	~Alien() ;
	void Update() override;
};

