#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <mutex>

#include "BaseSingleton.h"

class Logger : public BaseSingleton<Logger>
{
	FILE *m_pStream ;
	std::string m_Tag ;
	friend class BaseSingleton<Logger> ;
	Logger() ;
	~Logger() ;
public:
	Logger(const Logger&) = delete ;
	Logger & operator =(const Logger &) =delete ;
	void WriteLog(const char *pMessage) ;
	void SetTag(const char *pTag) ;
};

