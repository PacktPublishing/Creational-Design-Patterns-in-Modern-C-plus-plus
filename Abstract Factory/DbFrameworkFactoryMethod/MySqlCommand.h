#pragma once
#include "Command.h"
#include "MySqlRecordSet.h"

class MySqlCommand :
	public Command
{

public:
	void ExecuteCommand() override;
	MySqlRecordSet* ExecuteQuery() override;
};

