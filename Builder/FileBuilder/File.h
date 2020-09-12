#pragma once
#include <windows.h>
class File
{
	const char *m_pFileName{} ;
	DWORD m_DesiredAccess{} ;
	DWORD m_ShareMode{} ;
	LPSECURITY_ATTRIBUTES m_pSA{} ;
	DWORD m_CreationDisposition{} ;
	DWORD m_FlagsAttributes{} ;
	HANDLE m_hTemplateFile{} ;

	HANDLE m_hFile{} ;
public:

	File(const char* fileName, DWORD desiredAccess, DWORD shareMode, LPSECURITY_ATTRIBUTES sa,
	     DWORD creationDisposition, DWORD flagsAttributes, HANDLE templateFile);
	//Simple file
	File(const char *fileName, DWORD desiredAccess) ;

	//File with custom attributes
	File(const char *fileName, DWORD desiredAccess, DWORD flagsAttributes) ;

	
	DWORD Read(char *pBuffer, DWORD size) ;
	DWORD Write(const char *pBuffer, DWORD size) ;
	void Close() ;
	~File() ;
	BOOL IsOpen()const ;
	
};

