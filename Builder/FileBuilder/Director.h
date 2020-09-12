#pragma once
#include <windows.h>
class FileBuilder ;
class Director
{
	FileBuilder *m_pBuilder ;

public:
	Director(FileBuilder* builder);
	void Create(const char *pFileName, DWORD desiredAccess) ;
};

