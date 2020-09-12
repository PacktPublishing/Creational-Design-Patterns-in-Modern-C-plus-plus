#include "Director.h"
#include "FileBuilder.h"
Director::Director(FileBuilder* builder): m_pBuilder{builder} {
}

void Director::Create(const char* pFileName, DWORD desiredAccess) {
	m_pBuilder->SetFileName(pFileName) ;
	m_pBuilder->SetDesiredAccess(desiredAccess) ;
	m_pBuilder->SetShareMode() ;
	m_pBuilder->SetSecurityAttributes() ;
	m_pBuilder->SetCreationDisposition() ;
	m_pBuilder->SetFlagsAttributes() ;
	m_pBuilder->SetTemplateFile() ;
}
