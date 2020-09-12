#include "File.h"
#include <iostream>
void Read() {
	File f{"main.cpp", GENERIC_READ,
		FILE_SHARE_READ,
		nullptr,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		nullptr} ;
	if(!f.IsOpen()) {
		std::cout << "Could not open the file\n" ;
		return ;
	}
	constexpr int SIZE{128} ;
	char buffer[SIZE]{} ;
	while(f.Read(buffer, SIZE) != 0){
		std::cout << buffer  ;
	}
}
void Write() {
	File f{"data.txt", GENERIC_WRITE,
		FILE_SHARE_READ,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr} ;
	if(!f.IsOpen()) {
		std::cout << "Could not open the file\n" ;
		return  ;
	}
	auto str = "Hello world" ;
	f.Write(str, strlen(str)) ;
}
int main() {
	Write() ;
}
