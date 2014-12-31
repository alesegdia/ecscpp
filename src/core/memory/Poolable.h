#ifndef __POOLABLE_H__
#define __POOLABLE_H__

class Poolable
{
public:
	Poolable()
	{ }
	virtual ~Poolable()
	{ }

	virtual void setHandler(size_t h)
	{ _poolHandler = h; }
	virtual size_t getHandler()
	{ return _poolHandler; }
	virtual void cleanUp()
	{ }

protected:
	size_t _poolHandler;
};

#endif
