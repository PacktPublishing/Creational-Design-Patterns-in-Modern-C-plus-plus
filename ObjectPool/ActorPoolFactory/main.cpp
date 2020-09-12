#include <iostream>
#include <thread>
#include <vector>



#include "ActorPool.h"
#include "Missile.h"
#include "Alien.h"
std::vector<ActorPtr> actors{} ;

void Fire() {
	actors.push_back(ActorPool::AcquireActor("missile")) ;
	actors.push_back(ActorPool::AcquireActor("alien")) ;
}
void Animate() {
	for(auto &m : actors) {
		m->Update() ;
	}
}

void Explode() {
	using namespace std ;
	std::cout << "X\n" ;
	for(auto &m : actors) {
		m->SetVisibility(false) ;
	}
	actors.clear() ;
	std::this_thread::sleep_for(1s) ;
	std::cout << "\n\n" ;
}
void GameLoop() {
	using namespace std ;
	int loop{2} ;
	int counter{} ;
	while(loop != 0) {
		++counter ;
		if(counter == 1) {
			Fire() ;
		}
		if(counter >=1 && counter <= 5) {
			Animate() ;
		}
		if(counter > 5) {
			Explode() ; 
			counter = 0 ;
			--loop ;
		} 
		std::this_thread::sleep_for(1s) ;
	}
}

int main() {
	ActorPool::RegisterCreator("missile", []() {
		return std::make_shared<Missile>() ;
	}) ;
	ActorPool::RegisterCreator("alien", []() {
		return std::make_shared<Alien>() ;
	}) ;
	GameLoop() ;
}
