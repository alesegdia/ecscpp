#include "EntityProcessingSystem.h"

EntityProcessingSystem::EntityProcessingSystem()
{

}

EntityProcessingSystem::~EntityProcessingSystem()
{

}

void EntityProcessingSystem::process(Entity* e)
{
	std::cout << "EPSystem::process(Entity*e)\n";
}

void EntityProcessingSystem::process()
{
	for(auto it : _entities)
	{
		process(it.second);
	}
}

void EntityProcessingSystem::setFlags(ctflags_t flags)
{
	_flags = flags;
}

void EntityProcessingSystem::added(Entity* e)
{
	if(e->validateFlags(_flags))
		_entities[e->getEID()] = e;
}

void EntityProcessingSystem::deleted(Entity* e)
{
	// ask in #gamedev, #c++ says vector until benchmarking
	if(e->validateFlags(_flags))
		_entities.erase(e->getEID());
}

