#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <mutex>

class Logger
{
	struct Deleter{
		void operator()(Logger *p) {
			delete p ;
		}
	};
	FILE *m_pStream ;
	std::string m_Tag ;
	Logger() ;
	static Logger *m_pInstance ;
	//inline static std::unique_ptr<Logger, Deleter> m_pInstance{} ;
	~Logger() ;
public:
	Logger(const Logger&) = delete ;
	Logger & operator =(const Logger &) =delete ;
	static Logger & Instance() ;
	void WriteLog(const char *pMessage) ;
	void SetTag(const char *pTag) ;
};

