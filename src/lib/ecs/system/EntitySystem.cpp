
#include "EntitySystem.h"

EntitySystem::EntitySystem ()
{
	 // ctor
	 _flags = 0;
}

EntitySystem::~EntitySystem ()
{
	 // dtor
}


void EntitySystem::setFlags(ctflags_t flags)
{
	_flags = flags;
}

void EntitySystem::added(Entity* e)
{
	if(e->validateFlags(_flags))
		addEntity(e);
}

void EntitySystem::deleted(Entity* e)
{
	if(e->validateFlags(_flags))
		rmEntity(e);
}

void EntitySystem::process()
{

}

void EntitySystem::addEntity(Entity*e)
{

}

void EntitySystem::rmEntity(Entity*e)
{

}
