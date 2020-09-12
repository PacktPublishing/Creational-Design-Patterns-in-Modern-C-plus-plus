#include "Singleton.h"
#include <corecrt_math.h>

int main() {
	Singleton &s = Singleton::Instance() ;
	s.MethodA() ;

	//Singleton s2 ;
}
