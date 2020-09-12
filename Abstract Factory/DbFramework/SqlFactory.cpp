#include "SqlFactory.h"
#include "SqlCommand.h"
#include "SqlConnection.h"

Command* SqlFactory::CreateCommand() {
	return new SqlCommand{} ;
}

Connection* SqlFactory::CreateConnection() {
	return new SqlConnection{} ;
}
