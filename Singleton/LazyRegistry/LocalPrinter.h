#pragma once
#include <string>

#include "Printer.h"

class LocalPrinter : public Printer
{
	LocalPrinter()=default ;
public:
	static PrinterPtr GetInstance() ;
	void Print(const std::string & data) ;
};

