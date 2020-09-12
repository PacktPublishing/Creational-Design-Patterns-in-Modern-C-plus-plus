#include "Clock.h"
#include <ctime>
#include <sstream>
void Clock::CurrentTime() {
	time_t raw_time ;
	time(&raw_time) ;
	tm *local_time = localtime(&raw_time) ;
	m_Hour = local_time->tm_hour ;
	m_Minute = local_time->tm_min ;
	m_Second = local_time->tm_sec ;
}

Clock::Clock() {
	CurrentTime() ;
}

int Clock::GetHour()  {
	CurrentTime() ;
	return m_Hour ;
}

int Clock::GetMinute()  {
	CurrentTime() ;
	return m_Minute ;
}

int Clock::GetSecond()  {
	CurrentTime() ;
	return m_Second ;
}

std::string Clock::GetTimeString()  {
	CurrentTime() ;
	std::ostringstream out ;
	out << m_Hour <<":" << m_Minute << ":" << m_Second ;
	return out.str() ;
}
