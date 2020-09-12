#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Actor.h"
using ActorPtr = std::shared_ptr<Actor> ;
using Creator = std::function<ActorPtr()> ;
class ActorPool
{
	struct ActorInfo {
		std::vector<ActorPtr> m_Actors{} ;
		Creator m_Creator ;
	};
	inline static std::unordered_map<std::string, ActorInfo> m_ActorPool{} ;
	ActorPool() = default ;
	static ActorPtr InternalCreate(const std::string &key) ;
	static ActorPtr FindActor(const std::vector<ActorPtr> & actors) ;
public:
	static void RegisterCreator(const std::string &key, Creator creator) ;
	static ActorPtr AcquireActor(const std::string &key) ;
	static void ReleaseActor(const std::string &key, const ActorPtr & missile) ;
};

