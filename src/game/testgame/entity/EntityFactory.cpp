#include "EntityFactory.h"
#include "../component/TransformComponent.h"
#include "../component/RenderComponent.h"
#include "EntityWorld.h"
#include "../component/ComponentPools.h"

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{

}


void EntityFactory::setEntityWorld(EntityWorld* eworld)
{
	_eworld = eworld;
}

Entity* EntityFactory::acquireEntity()
{
	return Locator<Pool<Entity>>::get()->acquire();
}

template<typename ComponentType>
ComponentType* EntityFactory::acquireComponent()
{
	return Locator<Pool<ComponentType, pool_size<ComponentType>::size>>::get()->acquire();
}

Entity* EntityFactory::makeTestEntity()
{
	Entity* entity = acquireEntity();
	RenderComponent* rc = acquireComponent<RenderComponent>();
	TransformComponent* tc = acquireComponent<TransformComponent>();
	PlayerComponent* pc = acquireComponent<PlayerComponent>();

	rc->loadFromFile("persoese.gif");
	tc->setPosition(0,0);

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PlayerComponent>(pc);

	_eworld->pushEntity(entity);

	return entity;
}
