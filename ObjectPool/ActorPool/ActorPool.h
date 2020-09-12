#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Actor.h"
using ActorPtr = std::shared_ptr<Actor> ;
class ActorPool
{
	inline static std::unordered_map<std::string, std::vector<ActorPtr>> m_ActorPool{} ;
	ActorPool() = default ;
	static ActorPtr InternalCreate(const std::string &key) ;
	static ActorPtr FindActor(const std::vector<ActorPtr> & actors) ;
public:
	static ActorPtr AcquireActor(const std::string &key) ;
	static void ReleaseActor(const std::string &key, const ActorPtr & missile) ;
};

