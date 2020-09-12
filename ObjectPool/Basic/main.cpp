#include "ObjectPool.h"
#include "SharedObject.h"
int main() {
	auto s1 = ObjectPool::AcquireObject() ;
	s1->MethodA() ;
	s1->MethodB() ;

	auto s2 = ObjectPool::AcquireObject() ;
	s2->MethodA() ;
	s2->MethodB() ;

	ObjectPool::ReleaseObject(s1) ;
	auto s3 = ObjectPool::AcquireObject() ;
	s3->MethodA() ;
	s3->MethodB() ;
}
