#pragma once
#include "RecordSet.h"
#include <vector>

class MySqlRecordSet :
	public RecordSet
{
	const std::vector<std::string> m_Db{
		"Escape Plan",
		"Rambo",
		"Rocky Balboa",
		"Judge Dredd",
		"Demolition Man",
		"Cobra"
	} ;
	std::vector<std::string>::const_iterator m_Cursor ;
public:
	MySqlRecordSet();
	const std::string& Get() override;
	bool HasNext() override;
};

