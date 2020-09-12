
#include "Client.h"
#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

int main() {
	Client c ;
	c.SetPrototype(new ConcretePrototype2{}) ;
	c.Operation() ;
}
