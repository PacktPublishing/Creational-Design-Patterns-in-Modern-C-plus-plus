#include "ConcreteCreator.h"
#include "ConcreteProduct.h"

Product* ConcreteCreator::Create() {
	return new ConcreteProduct{} ;
}
