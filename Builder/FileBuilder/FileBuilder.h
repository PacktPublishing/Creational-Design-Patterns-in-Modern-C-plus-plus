#pragma once
#include <windows.h>
class File ;
class FileBuilder
{
public:
	virtual void SetFileName(const char *pFile) = 0 ;
	virtual void SetDesiredAccess(DWORD access) = 0 ;
	virtual void SetShareMode() = 0 ;
	virtual void SetSecurityAttributes() = 0 ;
	virtual void SetCreationDisposition() = 0 ;
	virtual void SetFlagsAttributes() = 0 ;
	virtual void SetTemplateFile() = 0 ;
	virtual ~FileBuilder()=default ;
	virtual File Build() = 0 ;
};

