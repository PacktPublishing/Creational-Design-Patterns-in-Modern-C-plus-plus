#include "EncryptedFileBuilder.h"
#include "File.h"
void EncryptedFileBuilder::SetFileName(const char* pFile) {
	m_pFileName = pFile ;
}

void EncryptedFileBuilder::SetDesiredAccess(DWORD access) {
	m_DesiredAccess = access ;
}

void EncryptedFileBuilder::SetShareMode() {
	m_ShareMode = 0 ;
}

void EncryptedFileBuilder::SetSecurityAttributes() {

}

void EncryptedFileBuilder::SetCreationDisposition() {
	
}

void EncryptedFileBuilder::SetFlagsAttributes() {
	m_FlagsAttributes = FILE_ATTRIBUTE_ENCRYPTED ;
}

void EncryptedFileBuilder::SetTemplateFile() {
}

File EncryptedFileBuilder::Build() {
	return File{m_pFileName, m_DesiredAccess,m_ShareMode,
	nullptr, CREATE_ALWAYS, m_FlagsAttributes, nullptr} ;
}
