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
	for(auto it : m_entities)
	{
		process(it.second);
	}
}

void EntityProcessingSystem::addEntity(Entity* e)
{
	m_entities[e->getEID()] = e;
	onEntityAdded(e);
}

void EntityProcessingSystem::removeEntity(Entity* e)
{
	m_entities.erase(e->getEID());
	onEntityDeleted(e);
}

