#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <stdinc.h>

class Entity;

class Component
{
public:
	virtual ~Component();

    /* Poolable interface */
    virtual void cleanUp();

    Entity* owner;
};

#endif
