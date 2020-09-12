#pragma once
#include "DbFactory.h"
class SqlFactory :
	public DbFactory
{

public:
	Command* CreateCommand() override;
	Connection* CreateConnection() override;
};

