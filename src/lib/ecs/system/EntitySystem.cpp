
#include "EntitySystem.h"

EntitySystem::EntitySystem ()
{
	 // ctor
}

EntitySystem::~EntitySystem ()
{
	 // dtor
}


void EntitySystem::added(Entity* e)
{
	if(m_aspect.fits(e->getFlags()))
	{
		addEntity(e);
	}
}

void EntitySystem::deleted(Entity* e)
{
	if(m_aspect.fits(e->getFlags()))
	{
		removeEntity(e);
	}
}

void EntitySystem::process()
{

}

Aspect &EntitySystem::aspect()
{
	return m_aspect;
}

void EntitySystem::addEntity(Entity*e)
{

}

void EntitySystem::removeEntity(Entity*e)
{

}
