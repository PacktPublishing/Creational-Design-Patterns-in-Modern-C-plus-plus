#pragma once
#include <memory>
#include "Document.h"
using DocumentPtr = std::unique_ptr<Document> ;
class Application
{
	DocumentPtr m_pDocument ;
	//Document *m_pDocument ;
public:
	void New() ;
	void Open() ;
	void Save() ;
	virtual DocumentPtr Create(){return nullptr ;}
	
};

