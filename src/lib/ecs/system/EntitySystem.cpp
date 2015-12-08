
#include "EntitySystem.h"

EntitySystem::EntitySystem ()
{
	 // ctor
     m_allFilter = 0;
}

EntitySystem::~EntitySystem ()
{
	 // dtor
}


void EntitySystem::setFlags(ctflags_t flags)
{
    m_allFilter = flags;
}

void EntitySystem::added(Entity* e)
{
    if(e->all(m_allFilter))
		addEntity(e);
}

void EntitySystem::deleted(Entity* e)
{
    if(e->all(m_allFilter))
		removeEntity(e);
}

void EntitySystem::process()
{

}

void EntitySystem::addEntity(Entity*e)
{

}

void EntitySystem::removeEntity(Entity*e)
{

}
