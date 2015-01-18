#include "EntityFactory.h"
#include "../component/TransformComponent.h"
#include "../component/RenderComponent.h"
#include "../component/PhysicComponent.h"
#include "../entity/GameWorld.h"
#include "../component/ComponentPools.h"
#include "../physics/Physics.h"

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{

}


void EntityFactory::Prepare(GameWorld* eworld, Physics* physics)
{
	_eworld = eworld;
	_physics = physics;
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

Entity* EntityFactory::MakePlayer( float x, float y )
{
	Entity* entity = acquireEntity();
	RenderComponent* rc = acquireComponent<RenderComponent>();
	TransformComponent* tc = acquireComponent<TransformComponent>();
	PlayerComponent* pc = acquireComponent<PlayerComponent>();
	PhysicComponent* phc = acquireComponent<PhysicComponent>();

	rc->loadFromFile("bbreaker.png");
	rc->zorder = RenderComponent::ZORDER_2;
	rc->SetRect(sf::IntRect(0,32,32,32));
	tc->setPosition(x,y);
	phc->body = _physics->CreatePlayerBody(32, 32);

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PlayerComponent>(pc);
	entity->addComponent<PhysicComponent>(phc);

	_eworld->pushEntity(entity);

	return entity;
}

/*
Entity* EntityFactory::SpawnEnemyCircle( float x, float y )
{
	Entity* entity = acquireEntity();
	RenderComponent* rc = acquireComponent<RenderComponent>();
	TransformComponent* tc = acquireComponent<TransformComponent>();
	PhysicComponent* pc = acquireComponent<PhysicComponent>();

	rc->loadFromFile("sheet.png");
	rc->SetRect(sf::IntRect(32,32,32,32));
	tc->setPosition(x,y);

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PhysicComponent>(pc);

	_eworld->pushEntity(entity);

	return entity;
}

Entity* EntityFactory::SpawnEnemyDiamond( float x, float y )
{
	Entity* entity = acquireEntity();
	RenderComponent* rc = acquireComponent<RenderComponent>();
	TransformComponent* tc = acquireComponent<TransformComponent>();
	PhysicComponent* pc = acquireComponent<PhysicComponent>();

	rc->loadFromFile("sheet.png");
	rc->SetRect(sf::IntRect(0,32,32,32));
	tc->setPosition(x,y);

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PhysicComponent>(pc);

	_eworld->pushEntity(entity);

	return entity;
}
*/

Entity* EntityFactory::SpawnBlock( float x, float y )
{
	Entity* entity = acquireEntity();
	RenderComponent* rc = acquireComponent<RenderComponent>();
	TransformComponent* tc = acquireComponent<TransformComponent>();
	PhysicComponent* phc = acquireComponent<PhysicComponent>();

	rc->loadFromFile("bbreaker.png");
	rc->SetRect(sf::IntRect(32,0,32,32));
	tc->setPosition(x,y);
	phc->body = _physics->CreateTileBody( x, y, 32, 32 );

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PhysicComponent>(phc);

	_eworld->pushEntity(entity);

	return entity;
}
