#include "Logger.h"
#include <iostream>
Logger *Logger::m_pInstance ;
std::mutex Logger::m_Mtx ;
Logger::Logger() {
	std::cout << __FUNCSIG__ << std::endl; 
	m_pStream = fopen("applog.txt", "w") ;
	atexit([]() {
		delete m_pInstance ;
	}) ;
}
std::once_flag flag ;
Logger& Logger::Instance() {
	//Double-check locking pattern
	//if (m_pInstance == nullptr) {
	//	m_Mtx.lock();
	//	if (m_pInstance == nullptr) {
	//		//m_pInstance = new Logger{};
	//		void *p=operator new (sizeof(Logger)) ;
	//		m_pInstance = static_cast<Logger*>(p) ;
	//		new(p)Logger{} ;
	//	}
	//	m_Mtx.unlock();
	//}
	//return *m_pInstance ; 

	//Meyer's singleton 
	/*static Logger instance ;
	return instance ;*/

	std::call_once(flag, [](int ) {
		m_pInstance = new Logger{} ;
	}, 5) ;
	return *m_pInstance ;

	//InitOnceExecuteOnce - Win32
	//pthread_once - Linux (POSIX)
}

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
