#pragma once
class SharedObject
{
	bool m_IsUsed{true} ;
public:
	bool IsUsed()const{return m_IsUsed ;}
	void SetUsedState(bool used) {
		m_IsUsed = used ;
	}
	void MethodA() ;
	void MethodB() ;
	void Reset() ;
};

