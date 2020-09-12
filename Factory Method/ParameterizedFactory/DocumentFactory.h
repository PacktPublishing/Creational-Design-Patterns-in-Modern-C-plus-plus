#pragma once
#include <string>
#include "Document.h"
class DocumentFactory
{
public:
	static DocumentPtr Create(const std::string &type) ;
};

