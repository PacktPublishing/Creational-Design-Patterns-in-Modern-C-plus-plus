#include "SqlRecordSet.h"

SqlRecordSet::SqlRecordSet() {
	m_Cursor = m_Db.begin() ;
}

const std::string& SqlRecordSet::Get() {
	return *m_Cursor++ ;
}

bool SqlRecordSet::HasNext() {
	return m_Cursor != m_Db.end() ;
}
