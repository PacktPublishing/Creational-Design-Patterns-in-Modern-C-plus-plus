#include "ActorPool.h"

#include <iostream>


#include "Alien.h"
#include "Missile.h"

ActorPtr ActorPool::InternalCreate(const std::string& key) {
	std::cout << "[POOL] Creating new actor of type :" << key << '\n' ;
	if(key == "missile") {
		return std::make_shared<Missile>() ;
	}else if(key == "alien") {
		return std::make_shared<Alien>() ;
	}
	return nullptr ;
}

ActorPtr ActorPool::FindActor(const std::vector<ActorPtr>& actors) {
	auto itActor = std::find_if(begin(actors), end(actors), 
		[](const auto &actor) {
			return !actor->IsVisible() ;
		}) ;
	if(itActor != end(actors)) {
		(*itActor)->SetVisibility(true) ;
		//Reset the state
		return *itActor ;
	}
	return nullptr ;
}

ActorPtr ActorPool::AcquireActor(const std::string &key) {
	ActorPtr actor{} ;
	if(auto it = m_ActorPool.find(key); it == end(m_ActorPool)) {
		actor = InternalCreate(key) ;
		m_ActorPool[key].push_back(actor) ;
		return actor ;
	}
	auto actors = m_ActorPool[key] ;
	actor = FindActor(actors) ;
	if(!actor) {
		actor = InternalCreate(key) ;
		actors.push_back(actor) ;
	}else {
		std::cout << "[POOL] Returning existing actor of type : " << key << '\n' ;
	}
	return actor ;
	
}

void ActorPool::ReleaseActor(const std::string &key, const ActorPtr& actor) {
	if(auto it = m_ActorPool.find(key); it == end(m_ActorPool)) {
		throw std::runtime_error{"Unknown key"} ;
	}
	auto actors = m_ActorPool[key] ;
	for(auto &a : actors) {
		if(a == actor) {
			a->SetVisibility(false) ;
			break ;
		}
	}
}
