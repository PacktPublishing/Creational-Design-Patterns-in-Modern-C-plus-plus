#include "ObjectPool.h"
class Test {
	Test() {
		
	}
public:
	void Foo() {
		
	}
	friend class TestAllocator ;
};
class TestAllocator {
	public:
	Test * operator()() {
		return new Test{} ;
	}
	void operator()(Test *p) {
		delete p ;
	}
	void Reset() {
		
	}
};
int main() {
	using IntPool = ObjectPool<int> ;
	auto p1 = IntPool::Acquire() ;
	IntPool::Acquire() ;
	auto p3 = IntPool::Acquire() ;

	IntPool::Release(p1) ;

	auto p4 = IntPool::Acquire() ;
	IntPool::Destroy() ;
}
