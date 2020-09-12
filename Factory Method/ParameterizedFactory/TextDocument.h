#pragma once
#include "Document.h"
class TextDocument :
	public Document
{

public:
	void Write() override;
	void Read() override;
};

