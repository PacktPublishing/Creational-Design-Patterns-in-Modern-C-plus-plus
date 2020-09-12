#pragma once
#include "Printer.h"
class PDFPrinter :
    public Printer
{
	static PDFPrinter m_Instance  ;
	PDFPrinter() ;
public:
	void Print(const std::string& data) override;
};

