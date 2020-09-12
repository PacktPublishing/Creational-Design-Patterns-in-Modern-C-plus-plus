#pragma once
#include <string>

class Connection
{
	std::string m_ConnectionString ;
public:
	void SetConnectionString(const std::string &connStr) {
		m_ConnectionString = connStr ;
	}
	const std::string & GetConnectionString()const {
		return m_ConnectionString ;
	}
	virtual void Open() = 0 ;
	virtual ~Connection() = default ;
};

