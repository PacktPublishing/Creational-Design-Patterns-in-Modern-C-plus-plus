#pragma once
#include <functional>
#include <mutex>
#include <unordered_map>

#include "Printer.h"
//Registry of singletons
//Multiton
using Creator = std::function<PrinterPtr()> ;
class PrinterProvider
{
	struct InstanceInfo {
		PrinterPtr m_Printer{} ;
		Creator m_Creator{} ;
	};
	inline static std::mutex m_mtx ;
	inline static std::unordered_map<std::string, InstanceInfo> m_Printers{} ;
	PrinterProvider() = default ;
public:
	static void RegisterCreator(const std::string &key, Creator creator) ;
	static PrinterPtr GetPrinter(const std::string &key) ;
};

