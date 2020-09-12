#pragma once
class Document
{
public: 
	virtual void Write() = 0 ;
	virtual void Read() = 0 ;
	virtual ~Document() = default ;
};

