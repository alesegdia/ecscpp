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

void EntityProcessingSystem::addEntity(Entity* e)
{
	_entities[e->getEID()] = e;
	onEntityAdded(e);
}

void EntityProcessingSystem::rmEntity(Entity* e)
{
	// ask in #gamedev, #c++ says vector until benchmarking
	_entities.erase(e->getEID());
	onEntityDeleted(e);
}

