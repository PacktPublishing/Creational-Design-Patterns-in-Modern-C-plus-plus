#pragma once
class Builder
{
public:
	virtual void BuildPart() = 0 ;
	virtual ~Builder()=default ;
};

