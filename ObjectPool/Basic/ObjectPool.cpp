#include "ObjectPool.h"

#include <iostream>

#include "SharedObject.h"
SharedObject* ObjectPool::AcquireObject() {
	for(auto & so : m_PooledObjects) {
		if(!so->IsUsed()) {
			std::cout << "[POOL] Returning an existing object\n" ;
			so->SetUsedState(true) ;
			so->Reset() ;
			return so ;
		}
	}
	std::cout << "[POOL] Creating a new object\n" ;
	SharedObject *so = new SharedObject{} ;
	m_PooledObjects.push_back(so) ;
	return so ;
}

void ObjectPool::ReleaseObject(SharedObject* pSO) {
	for(auto &so : m_PooledObjects) {
		if(so == pSO) {
			so->SetUsedState(false) ;
			//Optionally reset the state
		}
	}
}
