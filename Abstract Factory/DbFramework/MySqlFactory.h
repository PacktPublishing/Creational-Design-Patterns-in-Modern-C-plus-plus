#pragma once
#include "DbFactory.h"
class MySqlFactory :
	public DbFactory
{

public:
	Command* CreateCommand() override;
	Connection* CreateConnection() override;
};

