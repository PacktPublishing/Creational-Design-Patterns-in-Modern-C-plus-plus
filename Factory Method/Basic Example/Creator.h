#pragma once
class Product ;
class Creator
{
	Product *m_pProduct ;
public:
	void AnOperation() ;
	virtual Product * Create() {return nullptr;};
};

