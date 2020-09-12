#pragma once
class Singleton
{
	Singleton() =default ;
	static Singleton m_Instance ;
public:
	static Singleton & Instance() ;
	void MethodA() ;
	void MethodB() ;
};

