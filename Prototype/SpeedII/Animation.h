#pragma once
#include <string>
#include <string_view>
class Animation
{
	std::string m_AnimationData{} ;
public:
	Animation()=default ;
	Animation(std::string_view animFile) ;
	const std::string & GetAnimationData()const {
		return m_AnimationData ;
	}
	void SetAnimationData(const std::string &animationData) {
		m_AnimationData = animationData  ;
	}
};

