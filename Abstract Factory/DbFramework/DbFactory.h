#pragma once
class Command ;
class Connection ;
class DbFactory
{
public:
	virtual Command *CreateCommand() = 0 ;
	virtual Connection * CreateConnection() = 0 ;
	virtual ~DbFactory()=default ;
};

