#include "SqlConnection.h"
#include "SqlCommand.h"
#include "SqlRecordSet.h"
#include <iostream>

#include "MySqlCommand.h"
#include "MySqlConnection.h"
#include "DbFactory.h"

#define MYSQL
void UsingMacros() {
	Connection* pCon{};
#ifdef SQL
	pCon = new SqlConnection{};
#else defined MYSQL
	pCon = new MySqlConnection{};
#endif

	pCon->SetConnectionString("uid=umar;db=movies;table=actors");
	pCon->Open();

	Command* pCmd{};
#ifdef SQL
	pCmd = new SqlCommand{};
#else defined MYSQL
	pCmd = new MySqlCommand{};
#endif

	pCmd->SetConnection(pCon);
	pCmd->SetCommand("select * from actors");

	RecordSet* rec = pCmd->ExecuteQuery();
	while (rec->HasNext()) {
		std::cout << rec->Get() << std::endl;
	}

	delete pCon;
	delete pCmd;
	delete rec;
}

void Conditionals() {
	int dbtype = 0;
	Connection* pCon{};
	if (dbtype == 0)
		pCon = new SqlConnection{};
	else if (dbtype == 1)
		pCon = new MySqlConnection{};

	pCon->SetConnectionString("uid=umar;db=movies;table=actors");
	pCon->Open();

	Command* pCmd{};
	//if (dbtype == 0)
	//	pCmd = new SqlCommand{};
	//else if (dbtype == 1)
	pCmd = new MySqlCommand{};

	pCmd->SetConnection(pCon);
	pCmd->SetCommand("select * from actors");

	RecordSet* rec = pCmd->ExecuteQuery();
	while (rec->HasNext()) {
		std::cout << rec->Get() << std::endl;
	}

	delete pCon;
	delete pCmd;
	delete rec;
}
void FactoryMethod() {
	std::string_view db{"sql"} ;
	Connection* pCon{DbFactory::CreateConnection(db)};

	pCon->SetConnectionString("uid=umar;db=movies;table=actors");
	pCon->Open();

	Command* pCmd{DbFactory::CreateCommand("mysql")};


	pCmd->SetConnection(pCon);
	pCmd->SetCommand("select * from actors");

	RecordSet* rec = pCmd->ExecuteQuery();
	while (rec->HasNext()) {
		std::cout << rec->Get() << std::endl;
	}

	delete pCon;
	delete pCmd;
	delete rec;
}

int main() {
	FactoryMethod() ;
}
