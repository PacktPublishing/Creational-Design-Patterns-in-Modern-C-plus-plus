#include "PDFPrinter.h"

#include <iostream>


#include "PrinterProvider.h"
PDFPrinter PDFPrinter::m_Instance ;
PDFPrinter::PDFPrinter() {
	PrinterProvider::RegisterPrinter("pdf", this) ;
}

void PDFPrinter::Print(const std::string& data) {
	std::cout << "[PDFPRINTER]" << data<< '\n' ;
}
