#pragma once
#include "RecordSet.h"
#include <vector>

class SqlRecordSet :
	public RecordSet
{
	const std::vector<std::string> m_Db{
		"Terminator",
		"End of Days",
		"The 6th Day",
		"Predator",
		"Eraser",
		"Expendables"
	} ;
	std::vector<std::string>::const_iterator m_Cursor ;
public:

	SqlRecordSet();
	const std::string& Get() override;
	bool HasNext() override;
};

