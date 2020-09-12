#pragma once
#include <string_view>
class Connection ;
class Command ;
class DbFactory
{
public:
	static Connection * CreateConnection(std::string_view type) ;
	static Command * CreateCommand(std::string_view type) ;
};

