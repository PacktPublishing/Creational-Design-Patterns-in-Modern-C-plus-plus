#include "Logger.h"

void OpenConnection() {
	Logger &lg = Logger::Instance() ;
	lg.WriteLog("Attempting to open a connection") ;
}
int main() {
	std::thread t1{[]() {
		Logger &lg = Logger::Instance() ;
		lg.WriteLog("Thread 1 has started") ;
	}} ;
	std::thread t2{[]() {
		Logger &lg = Logger::Instance() ;
		lg.WriteLog("Thread 2 has started") ;
	}} ;
	t1.join() ;
	t2.join() ;
	
	/*Logger &lg = Logger::Instance() ;
	lg.SetTag("192.168.1.101") ;
	lg.WriteLog("Application has started") ;
	OpenConnection() ;
	lg.WriteLog("Application is shutting down") ;*/

}
