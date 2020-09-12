#include "Director.h"
#include <iostream>
#include "Builder.h"
Director::Director(Builder* builder): builder{builder} {
	std::cout << "[Director] Created\n" ;
}

void Director::Construct() {
	std::cout << "[Director] Construction process started\n" ;
	builder->BuildPart() ;
}
