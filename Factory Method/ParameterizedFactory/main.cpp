#include "Application.h"
#include <algorithm>
#include <map>

void Foo(std::unique_ptr<int> u1, std::unique_ptr<int> u2){
}

template<typename Type, typename...Args>
std::unique_ptr<Type> MakeUnique(Args&&...args) {
	return std::unique_ptr<Type>{
		new Type{std::forward<Args>(args)...}
	} ;
}
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	Application app ;
	app.New() ;
	app.Open() ;
	app.Save() ;

	int *p = new int{5} ;

	delete p ;

	std::unique_ptr<int> p2 {new int{5}} ;

	auto p3 = std::make_unique<int>(5) ;
	
	Foo(
		std::make_unique<int>(1),
		std::make_unique<int>(2)
	) ;

	auto p4 = std::make_shared<int>(5) ;
	
	std::shared_ptr<int> p5 {new int{5}} ;


	std::multimap<int, int> m ;
	m.insert(std::pair<int,int>{1,2}) ;
	m.insert(std::make_pair(1,2)) ;
	//m[1] = 2 ;

	auto t1 = std::make_tuple(1, "Hello", 5) ;
	
	std::tuple<int, const char *, int> t2{1, "Hello", 5} ;
	
}
