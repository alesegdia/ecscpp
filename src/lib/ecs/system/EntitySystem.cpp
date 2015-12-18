
#include "EntitySystem.h"

EntitySystem::EntitySystem ()
{
	 // ctor
}

EntitySystem::~EntitySystem ()
{
	 // dtor
}


void EntitySystem::entityAdded(Entity* e)
{
	if(m_aspect.fits(e->getFlags()))
	{
		m_entities[e->getEID()] = e;
		onEntityAdded(e);
	}
}

void EntitySystem::entityDeleted(Entity* e)
{
	if(m_aspect.fits(e->getFlags()))
	{
		m_entities.erase(e->getEID());
		onEntityDeleted(e);
	}
}

void EntitySystem::process()
{
	for(auto it : m_entities)
	{
		process(it.second);
	}
}

Aspect &EntitySystem::aspect()
{
	return m_aspect;
}

void EntitySystem::process(Entity *e)
{

}

void EntitySystem::onEntityAdded(Entity *e)
{

}

void EntitySystem::onEntityDeleted(Entity *e)
{

}

void EntitySystem::onEntityChanged(Entity *e)
{

}

