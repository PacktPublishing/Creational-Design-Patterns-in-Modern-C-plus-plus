#include "LocalPrinter.h"
#include "PrinterProvider.h"
#include "PDFPrinter.h"

void PrintSales() {
	auto p = PrinterProvider::GetPrinter("local") ;
	if(p)
		p->Print("Sales data") ;
}

int main() {
	PrinterProvider::RegisterCreator("local", &LocalPrinter::GetInstance) ;
	PrinterProvider::RegisterCreator("pdf", &PDFPrinter::GetInstance) ;
	/*auto p = PrinterProvider::GetPrinter("pdf");
	if(p)
		p->Print("Printing data to the printer") ;
	PrintSales() ; */
}
