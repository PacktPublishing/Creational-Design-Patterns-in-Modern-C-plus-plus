#pragma once
class Prototype ;
class Client
{
	Prototype *prototype ;
public:
	void SetPrototype(Prototype *p) {
		prototype = p ;
	}
	void Operation() ;
};

