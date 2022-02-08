#include "Alloc.h"
#include <memory>


template<class T>
class m_memory
{
public:
	
	m_memory(size_t n)
	{
		data=alloc.allocate(sizeof(T) * n);
	}
	T* data;
private:
	std::allocator<T> alloc;
};