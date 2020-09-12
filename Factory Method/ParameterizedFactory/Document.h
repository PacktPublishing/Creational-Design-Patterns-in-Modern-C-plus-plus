#pragma once
#include <memory>

class Document
{
public:
	virtual void Write() = 0 ;
	virtual void Read() = 0 ;
	virtual ~Document() = default ;
};
using DocumentPtr = std::unique_ptr<Document> ;

