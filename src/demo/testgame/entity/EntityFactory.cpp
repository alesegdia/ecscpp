#include "EntityFactory.h"
#include "../component/TransformComponent.h"
#include "../component/RenderComponent.h"
#include "../entity/GameWorld.h"
#include "../component/ComponentPools.h"

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{

}


void EntityFactory::setEntityWorld(GameWorld* eworld)
{
	_eworld = eworld;
}

Entity* EntityFactory::acquireEntity()
{
	Entity* ret = Locator<Pool<Entity>>::get()->acquire();
	ret->OnCreate();
	return ret;
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

	rc->loadFromFile("nosghy-main-sheet.png");
	tc->setPosition(0,0);

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PlayerComponent>(pc);

	_eworld->pushEntity(entity);

	return entity;
}
