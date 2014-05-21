#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "stdinc.h"
#include "Poolable.h"

class Component : Poolable
{
public:
	Component();
	virtual ~Component()=0;

	/* Poolable interface */
	virtual size_t getHandler();
	virtual void setHandler(size_t handler);
	virtual void cleanUp();
};

#endif
