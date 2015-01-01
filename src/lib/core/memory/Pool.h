#ifndef __POOL_H__
#define __POOL_H__

#include <stdinc.h>
//#include "Components.h"

// Type must have getHandler() and setHandler();
template<typename Type, size_t POOL_SIZE=128>
class Pool
{
public:
	Pool()
	{
		// allocate POOL_SIZE elements in stack

		// fill free slots
		for(size_t i = 0; i < POOL_SIZE; i++)
		{
			_free.push(i);
			_bucket[i].setHandler(i);
		}
	}
	~Pool()
	{

	}

	Type* acquire()
	{
		if(!_free.empty())
		{
			size_t handler;
			handler = _free.top();
			_free.pop();
			return &_bucket[handler];
		}
		assert(0 && "POOL LIMITS EXCEEDED!");
	}

	void release(size_t handler)
	{
		_free.push(handler);
	}

private:
	Type _bucket[POOL_SIZE];
	//bool _inUse[POOL_SIZE];
	std::stack<size_t> _free;
};

#endif
