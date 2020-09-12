#include "Printer.h"

#include "LocalPrinter.h"


Printer& Printer::GetInstance(const std::string& key) {
	if(key == "local") {
		return LocalPrinter::GetInstance() ;
	}
}
