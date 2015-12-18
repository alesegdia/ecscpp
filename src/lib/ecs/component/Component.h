#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <stdinc.h>

class Entity;

/**
 * @brief The Component class represents each bit an Entity is composed of
 */
class Component
{
public:
	virtual ~Component();

	/**
	 * @brief entity owner of this component
	 */
    Entity* owner;
};

#endif
