#pragma once
#include "FileBuilder.h"
class SimpleFileBuilder :
	public FileBuilder
{
	const char *m_pFileName{} ;
	DWORD m_DesiredAccess{} ;
public:

	void SetFileName(const char* pFile) override;
	void SetDesiredAccess(DWORD access) override;
	void SetShareMode() override;
	void SetSecurityAttributes() override;
	void SetCreationDisposition() override;
	void SetFlagsAttributes() override;
	void SetTemplateFile() override;
	File Build() override;
};

