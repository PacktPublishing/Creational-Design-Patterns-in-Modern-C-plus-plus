#include "ConcreteCreator2.h"
#include "ConcreteProduct2.h"

Product* ConcreteCreator2::Create() {
	return new ConcreteProduct2{} ;
}
