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
	class Builder {
		const char* m_pFileName{};
		DWORD m_DesiredAccess{};
		DWORD m_ShareMode{};
		LPSECURITY_ATTRIBUTES m_pSA{};
		DWORD m_CreationDisposition{CREATE_ALWAYS};
		DWORD m_FlagsAttributes{FILE_ATTRIBUTE_NORMAL};
		HANDLE m_hTemplateFile{};
	public:

		Builder(const Builder& other) = delete;

		Builder(Builder&& other) noexcept
			: m_pFileName{other.m_pFileName},
			  m_DesiredAccess{other.m_DesiredAccess},
			  m_ShareMode{other.m_ShareMode},
			  m_pSA{other.m_pSA},
			  m_CreationDisposition{other.m_CreationDisposition},
			  m_FlagsAttributes{other.m_FlagsAttributes},
			  m_hTemplateFile{other.m_hTemplateFile} {
			other.m_pFileName = nullptr ;
			other.m_DesiredAccess = 0 ;
			other.m_ShareMode = 0 ;
			other.m_pSA = nullptr ;
			other.m_CreationDisposition = 0 ;
			other.m_FlagsAttributes = 0 ;
			other.m_hTemplateFile = nullptr ;
		}

		Builder& operator=(const Builder& other) = delete;

		Builder& operator=(Builder&& other) noexcept {
			if (this == &other)
				return *this;
			m_pFileName = other.m_pFileName;
			m_DesiredAccess = other.m_DesiredAccess;
			m_ShareMode = other.m_ShareMode;
			m_pSA = other.m_pSA;
			m_CreationDisposition = other.m_CreationDisposition;
			m_FlagsAttributes = other.m_FlagsAttributes;
			m_hTemplateFile = other.m_hTemplateFile;
			other.m_pFileName = nullptr ;
			other.m_DesiredAccess = 0 ;
			other.m_ShareMode = 0 ;
			other.m_pSA = nullptr ;
			other.m_CreationDisposition = 0 ;
			other.m_FlagsAttributes = 0 ;
			other.m_hTemplateFile = nullptr ;
			return *this;
		}

		Builder(const char *pFileName, DWORD desiredAcces):
		m_pFileName{pFileName},
		m_DesiredAccess{desiredAcces} {
			
		}
		Builder & ShareMode(DWORD shareMode) {
			m_ShareMode = shareMode ;
			return *this; 
		}
		Builder & SecurityAttributes(LPSECURITY_ATTRIBUTES lpsa) {
			m_pSA = lpsa ;
			return *this; 
		}
		Builder & CreationDisposition(DWORD creationDisposition) {
			m_CreationDisposition = creationDisposition ;
			return *this; 
		}
		Builder & FlagsAttributes(DWORD flagsAttributes) {
			m_FlagsAttributes = flagsAttributes ;
			return *this; 
		}
		Builder & TemplateFile(HANDLE templateFile) {
			m_hTemplateFile = templateFile ;
			return *this; 
		}
		File Build() {
			return File{m_pFileName, m_DesiredAccess, m_ShareMode,m_pSA,
			m_CreationDisposition, m_FlagsAttributes, m_hTemplateFile} ;
		}
	};
};

