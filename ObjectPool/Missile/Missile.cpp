#include "Missile.h"

#include <iostream>

void Missile::SetVisible(bool visible) {
	m_IsVisible = visible ;
}

bool Missile::IsVisible() const {
	return m_IsVisible ;
}

Missile::Missile() {
	std::cout << "++++ Missile Created\n" ;
}

Missile::~Missile() {
	std::cout << "~~~~ Missile Destroyed\n" ;
}

void Missile::Update() {
	std::cout << "-> " ;
}
