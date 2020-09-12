#pragma once
#include <vector>
#include <iostream>
template<typename T>
class DefaultAllocator {
public:
	T * operator()() {
		return new T{} ;
	}
	void operator()(T *p) {
		delete p ;
	}
	void Reset() {
		
	}
};
template<
	typename T,
	size_t max_size=std::numeric_limits<size_t>::max(),
	typename AllocatorT=DefaultAllocator<T>>
class ObjectPool
{
	struct ObjectInfo {
		bool m_IsUsed{} ;
		T *m_pObject{} ;
	};
	inline static std::vector<ObjectInfo> m_PooledObjects{} ;
	inline static AllocatorT m_Allocator{} ;
public:
	[[nodiscard("Object will remain unused")]]
	static T * Acquire() {
		for(auto &obj : m_PooledObjects) {
			if(!obj.m_IsUsed) {
				obj.m_IsUsed = true ;
				std::cout << "[POOL] Returning an existing object\n" ;
				return obj.m_pObject ;
			}
		}
		if(m_PooledObjects.size() == max_size) {
			std::cout << "Pool is full!\n" ;
			return nullptr ;
		}
		std::cout << "[POOL] Creating a new object\n" ;
		auto pObj = m_Allocator() ;
		m_PooledObjects.push_back({true,pObj}) ;
		return pObj ;
	}
	static void Release(const T *pObj) {
		for(auto &obj : m_PooledObjects) {
			if(obj.m_pObject == pObj) {
				obj.m_IsUsed = false ;
				break ;
			}
		}
	}
	static void Destroy() {
		for(auto &obj : m_PooledObjects) {
			if(obj.m_IsUsed) {
				std::cout << "WARNING! Deleting an object still in use\n" ;
			}
			m_Allocator(obj.m_pObject) ;
		}
		m_Allocator.Reset() ;
		m_PooledObjects.clear() ;
	}
};

