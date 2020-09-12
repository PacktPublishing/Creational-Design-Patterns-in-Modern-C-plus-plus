#include "Creator.h"
#include "Product.h"
//#include "ConcreteProduct.h"

void Creator::AnOperation() {
	//m_pProduct = new ConcreteProduct{} ;
	m_pProduct = Create() ;
	m_pProduct->Operation() ;
}
