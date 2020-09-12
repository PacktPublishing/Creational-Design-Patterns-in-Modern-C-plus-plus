#include "File.h"
#include <stdexcept>
#include <iostream>

File::File(const char* fileName, DWORD desiredAccess, DWORD shareMode, LPSECURITY_ATTRIBUTES sa,
           DWORD creationDisposition, DWORD flagsAttributes,
           HANDLE templateFile) :
m_pFileName{ fileName },
m_DesiredAccess{desiredAccess},
m_ShareMode{ shareMode },
m_pSA{ sa },
m_CreationDisposition{creationDisposition},
m_FlagsAttributes{flagsAttributes},
m_hTemplateFile{templateFile} {
	
	m_hFile = CreateFileA(fileName, 
		desiredAccess, 
		shareMode, 
		sa,
		creationDisposition, 
		flagsAttributes, 
		templateFile) ;
	if(m_hFile == INVALID_HANDLE_VALUE) {
		throw std::runtime_error{"File error"} ;
	}
}

File::File(const char* fileName, DWORD desiredAccess)
	:File{fileName, desiredAccess, FILE_ATTRIBUTE_NORMAL}
{

}

File::File(const char* fileName, 
	DWORD desiredAccess, 
	DWORD flagsAttributes):
File{fileName, desiredAccess, 0, nullptr, CREATE_ALWAYS,flagsAttributes, nullptr}
{

}

DWORD File::Read(char* pBuffer, DWORD size) {
	DWORD read{} ;
	ZeroMemory(pBuffer, size) ;
	if(ReadFile(m_hFile, pBuffer, size-1, &read, nullptr) == FALSE) {
		throw std::runtime_error{"Error while reading"} ;
	}
	return read ;
}

DWORD File::Write(const char* pBuffer, DWORD size) {
	DWORD written{} ;
	if(WriteFile(m_hFile, pBuffer, size, &written, nullptr) == FALSE) {
		throw std::runtime_error{"Error while writing"} ;
	}
	return written ;
}

void File::Close() {
	CloseHandle(m_hFile) ;
	m_hFile = nullptr; 
}

File::~File() {
	if(m_hFile)
		CloseHandle(m_hFile) ;
}

BOOL File::IsOpen() const {
	return m_hFile != nullptr ;
}

