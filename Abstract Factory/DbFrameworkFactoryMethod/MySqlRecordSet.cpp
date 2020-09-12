#include "MySqlRecordSet.h"

MySqlRecordSet::MySqlRecordSet() {
	m_Cursor = m_Db.begin() ;
}

const std::string& MySqlRecordSet::Get() {
	return *m_Cursor++ ;
}

bool MySqlRecordSet::HasNext() {
	return m_Cursor != m_Db.end() ;
}
