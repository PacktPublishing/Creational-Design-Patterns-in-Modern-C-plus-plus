#include "ConcreteBuilder.h"
#include "Director.h"
#include "Product.h"
int main() {
	ConcreteBuilder builder ;
	Director director{&builder} ;
	director.Construct() ;
	Product *p = builder.GetResult() ;
	delete p ;
}
