#pragma once
#include "Document.h"
class SpreadsheetDocument :
	public Document
{

public:
	void Write() override;
	void Read() override;
};

