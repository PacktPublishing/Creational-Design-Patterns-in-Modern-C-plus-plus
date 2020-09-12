#include "ActorPool.h"

#include <iostream>

ActorPtr ActorPool::InternalCreate(const std::string& key) {
	ActorPtr actor{} ;
	if(!m_ActorPool[key].m_Creator) {
		std::cout << "Creator not registered\n" ;
		return actor ;
	}
	actor = m_ActorPool[key].m_Creator() ;
	m_ActorPool[key].m_Actors.push_back(actor) ;
	return actor ;
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
	if(auto it = m_ActorPool.find(key); it == end(m_ActorPool)) {
		return InternalCreate(key) ;
	}
	ActorPtr actor{} ;
	
	auto actors = m_ActorPool[key].m_Actors ;
	actor = FindActor(actors) ;
	if(!actor) {
		actor = InternalCreate(key) ;
	}else {
		std::cout << "[POOL] Returning existing actor of type : " << key << '\n' ;
	}
	return actor ;
	
}

void ActorPool::ReleaseActor(const std::string &key, const ActorPtr& actor) {
	if(auto it = m_ActorPool.find(key); it == end(m_ActorPool)) {
		throw std::runtime_error{"Unknown key"} ;
	}
	auto actors = m_ActorPool[key].m_Actors ;
	for(auto &a : actors) {
		if(a == actor) {
			a->SetVisibility(false) ;
			break ;
		}
	}
}
void ActorPool::RegisterCreator(const std::string& key, Creator creator) {
	m_ActorPool[key].m_Creator = creator ;
}

