#pragma once
#include <string>

class RecordSet
{
public:
	virtual const std::string & Get() = 0 ;
	virtual bool HasNext() = 0 ;
	virtual ~RecordSet() =default ;
};

