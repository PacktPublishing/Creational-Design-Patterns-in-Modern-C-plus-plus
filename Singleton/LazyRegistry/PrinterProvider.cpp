#include "PrinterProvider.h"

#include <iostream>

void PrinterProvider::RegisterCreator(const std::string& key, Creator creator) {
	std::lock_guard lock{m_mtx} ;
	if(auto it = m_Printers.find(key); it == end(m_Printers)) {
		m_Printers[key].m_Creator = creator ;
	}else {
		std::cout << "Already registered\n" ;
	}
}

PrinterPtr PrinterProvider::GetPrinter(const std::string& key) {
	std::lock_guard lock{m_mtx} ;
	if(auto it = m_Printers.find(key); it != end(m_Printers)) {
		if(!m_Printers[key].m_Printer) {
			m_Printers[key].m_Printer = m_Printers[key].m_Creator() ;
		}
		return m_Printers[key].m_Printer; 
	}
	std::cout << "Unknown key\n" ;
	return nullptr ;
}
