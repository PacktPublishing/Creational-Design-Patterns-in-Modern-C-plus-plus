#include "Logger.h"

void OpenConnection() {
	Logger &lg = Logger::Instance() ;
	lg.WriteLog("Attempting to open a connection") ;
}
int main() {
	Logger &lg = Logger::Instance() ;
	lg.SetTag("192.168.1.101") ;
	lg.WriteLog("Application has started") ;
	OpenConnection() ;
	lg.WriteLog("Application is shutting down") ;
	//auto *p = &lg ;
	//delete p ;
}
