#pragma once
#include "Connection.h"
class MySqlConnection :
	public Connection
{

public:
	void Open() override;
};

