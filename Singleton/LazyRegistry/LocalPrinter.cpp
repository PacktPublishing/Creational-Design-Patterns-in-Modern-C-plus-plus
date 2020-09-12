#include "LocalPrinter.h"
#include <iostream>

#include "PrinterProvider.h"

PrinterPtr LocalPrinter::GetInstance() {
	/*static LocalPrinter instance ;
	return instance ;*/
	std::cout << "LocalPrinter instance created\n" ;
	return std::shared_ptr<LocalPrinter>{new LocalPrinter{}} ;
}

void LocalPrinter::Print(const std::string& data) {
	std::cout << "[LOCALPRINTER]" << data << '\n' ;
}

