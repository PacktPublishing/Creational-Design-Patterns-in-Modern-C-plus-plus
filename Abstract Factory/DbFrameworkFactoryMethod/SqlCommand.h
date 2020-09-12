#pragma once
#include "Command.h"
#include "SqlRecordSet.h"

class SqlCommand :
	public Command
{

public:
	void ExecuteCommand() override;
	SqlRecordSet* ExecuteQuery() override;
};

