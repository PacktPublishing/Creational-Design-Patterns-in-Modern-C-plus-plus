#include "LocalPrinter.h"
#include "PrinterProvider.h"

void PrintSales() {
	auto p = PrinterProvider::GetPrinterPtr("local") ;
	if(p)
		p->Print("Sales data") ;
}

int main() {
	auto p = PrinterProvider::GetPrinterPtr("pdf");
	if(p)
		p->Print("Printing data to the printer") ;
	PrintSales() ; 
}
