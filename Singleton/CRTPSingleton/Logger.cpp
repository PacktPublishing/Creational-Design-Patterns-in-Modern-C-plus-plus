#include "Logger.h"
#include <iostream>
Logger::Logger() {
	std::cout << __FUNCSIG__ << std::endl; 
	m_pStream = fopen("applog.txt", "w") ;
}
std::once_flag flag ;


Logger::~Logger() {
	std::cout << __FUNCSIG__ << std::endl; 
	fclose(m_pStream) ;
}

void Logger::WriteLog(const char* pMessage) {
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage) ;
	fflush(m_pStream) ;
}

void Logger::SetTag(const char* pTag) {
	m_Tag = pTag ;
}
