#pragma once
#include "Application.h"
class SpreadSheetApplication :
	public Application
{

public:
	DocumentPtr Create() override;
};

