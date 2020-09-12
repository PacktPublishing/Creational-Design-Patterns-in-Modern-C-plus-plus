#include "Animation.h"

#include <iostream>
#include <thread>

Animation::Animation(std::string_view animFile) {
	using namespace std ;
	std::cout << "[Animation] Loading:" << animFile<<' ' ;
	for(int i = 0 ; i < 10; ++i) {
		std::cout << '.' ;
		std::this_thread::sleep_for(200ms) ;
	}
	std::cout << '\n' ;
	m_AnimationData.assign("^^^^^^") ;
}
