#include <iostream>
#include <thread>
#include <vector>


#include "Missile.h"
std::vector<std::shared_ptr<Missile>> missiles{} ;

void Fire() {
	missiles.push_back(std::make_shared<Missile>()) ;
	missiles.push_back(std::make_shared<Missile>()) ;
}
void Animate() {
	for(auto &m : missiles) {
		m->Update() ;
	}
}

void Explode() {
	using namespace std ;
	std::cout << "X\n" ;
	for(auto &m : missiles) {
		m->SetVisible(false) ;
	}
	missiles.clear() ;
	std::this_thread::sleep_for(1s) ;
	std::cout << "\n\n" ;
}
void GameLoop() {
	using namespace std ;
	int counter{} ;
	while(true) {
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
		} 
		std::this_thread::sleep_for(1s) ;
	}
}

int main() {
	GameLoop() ;
}
