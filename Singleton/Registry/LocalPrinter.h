#pragma once
#include <string>

#include "Printer.h"

class LocalPrinter : public Printer
{
	static LocalPrinter m_Instance ;
	LocalPrinter()  ;
public:
	static  LocalPrinter & GetInstance() ;
	void Print(const std::string & data) ;
};

