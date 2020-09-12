#include "Application.h"
#include "Document.h"

void Application::New() {
	m_pDocument = Create() ;
}

void Application::Open() {
	m_pDocument = Create() ;
	m_pDocument->Read() ;
}

void Application::Save() {
	m_pDocument->Write() ;
}
