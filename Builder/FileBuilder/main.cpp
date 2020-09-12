#include "SimpleFileBuilder.h"
#include "Director.h"
#include "File.h"
#include "EncryptedFileBuilder.h"

int main() {
	EncryptedFileBuilder builder{} ;
	Director director{&builder} ;

	director.Create("myfile.txt", FILE_GENERIC_WRITE) ;
	File file = builder.Build() ;
	file.Write("Hello", 5) ;
}
