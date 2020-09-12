#pragma once
#include <memory>
#include "Document.h"
class Application
{
	DocumentPtr m_pDocument ;
	//Document *m_pDocument ;
public:
	void New() ;
	void Open() ;
	void Save() ;
};

