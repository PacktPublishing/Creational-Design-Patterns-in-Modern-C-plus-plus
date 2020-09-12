#include "File.h"
#include <iostream>
#include <string>
int main() {
	SECURITY_ATTRIBUTES sa{} ;
	File::Builder builder{"source.cpp", FILE_GENERIC_READ} ;
	auto f =builder.FlagsAttributes(FILE_ATTRIBUTE_NORMAL) 
		.CreationDisposition(OPEN_EXISTING) 
		.ShareMode(FILE_SHARE_READ) 
		.SecurityAttributes(&sa)
		.Build() ;
	char buffer[1024]{} ;
	f.Read(buffer, 1024) ;
	std::cout << buffer ;


	std::string name{"Umar"} ;
	int id{1001} ;
	std::cout << "Name:" << name << std::endl ;
	std::cout << "Id:" << id << std::endl; 
	
	std::cout << "Name:" ;
	std::cout << name ;
	std::cout << std::endl ;

	std::cout << "Id:" ;
	std::cout << id ;
	std::cout << std::endl;
	
}
