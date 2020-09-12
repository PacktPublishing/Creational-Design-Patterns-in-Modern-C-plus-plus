#include "SimpleFileBuilder.h"
#include "File.h"
void SimpleFileBuilder::SetFileName(const char* pFile) {
	m_pFileName = pFile ;
}

void SimpleFileBuilder::SetDesiredAccess(DWORD access) {
	m_DesiredAccess = access ;
}

void SimpleFileBuilder::SetShareMode() {
}

void SimpleFileBuilder::SetSecurityAttributes() {
}

void SimpleFileBuilder::SetCreationDisposition() {
}

void SimpleFileBuilder::SetFlagsAttributes() {
}

void SimpleFileBuilder::SetTemplateFile() {
}

File SimpleFileBuilder::Build() {
	return File{m_pFileName, m_DesiredAccess,0,
	nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr} ;
}
