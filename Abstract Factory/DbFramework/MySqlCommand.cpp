#include "MySqlCommand.h"
#include <iostream>
#include "Connection.h"
void MySqlCommand::ExecuteCommand() {
	std::cout
		 << "[MySqlCommand] Executing command on :"
		<< m_pConnection->GetConnectionString()
		<< std::endl; 
}

MySqlRecordSet* MySqlCommand::ExecuteQuery() {
	std::cout << "[MySqlCommand] Executing query\n" ;
	return new MySqlRecordSet{} ;
}
