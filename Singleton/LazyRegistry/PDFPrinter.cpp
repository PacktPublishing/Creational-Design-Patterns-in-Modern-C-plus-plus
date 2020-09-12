#include "PDFPrinter.h"

#include <iostream>


#include "PrinterProvider.h"
PrinterPtr PDFPrinter::GetInstance() {
	std::cout << "PDFPrinter instance created\n" ;
	return std::shared_ptr<PDFPrinter>{new PDFPrinter{}} ;
}


void PDFPrinter::Print(const std::string& data) {
	std::cout << "[PDFPRINTER]" << data<< '\n' ;
}
