#pragma once
class Builder ;
class Director
{
	Builder *builder ;
public:

	Director(Builder* builder);
	void Construct( );
};

