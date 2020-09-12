#pragma once
#include <memory>
#include <string>

class Printer
{
protected:
	Printer() =default ;
public:
	Printer(const Printer &) = delete ;
	Printer & operator=(const Printer &) = delete ;
	virtual ~Printer()=default ;
	virtual void Print(const std::string &data)=0 ;
};
using PrinterPtr = std::shared_ptr<Printer> ;

