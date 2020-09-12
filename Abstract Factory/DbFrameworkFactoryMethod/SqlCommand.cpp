#include "SqlCommand.h"
#include <iostream>
#include "Connection.h"
#include "SqlRecordSet.h"

void SqlCommand::ExecuteCommand() {
	std::cout
		<< "[SqlCommand] Executing command on"
		<< m_pConnection->GetConnectionString()
		<< std::endl; 
}

SqlRecordSet* SqlCommand::ExecuteQuery() {
	std::cout << "[SqlCommand] Executing query\n" ;
	return new SqlRecordSet() ;
}
