#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <stdinc.h>

class Component
{
public:
	virtual ~Component();

	/* Poolable interface */
	virtual void cleanUp();
};

#endif
