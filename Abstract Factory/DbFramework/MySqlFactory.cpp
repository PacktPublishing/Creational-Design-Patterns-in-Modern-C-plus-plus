#include "MySqlFactory.h"
#include "MySqlCommand.h"
#include "MySqlConnection.h"

Command* MySqlFactory::CreateCommand() {
	return  new MySqlCommand{} ;
}

Connection* MySqlFactory::CreateConnection() {
	return new MySqlConnection{} ;
}
