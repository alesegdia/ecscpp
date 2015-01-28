#include "EntityFactory.h"
#include "../component/TransformComponent.h"
#include "../component/RenderComponent.h"
#include "../component/PhysicComponent.h"
#include "../entity/GameWorld.h"
#include "../component/ComponentPools.h"
#include "../physics/Physics.h"
#include "../Assets.h"

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

	Assets* assets = Locator<Assets>::get();
	rc->LoadFromTexture(&(assets->playertex));
	rc->zorder = RenderComponent::ZORDER_2;
	rc->SetRect(sf::IntRect(0,0,32,34));
	tc->setPosition(x,y);
	phc->body = _physics->CreateCircleBody( 0, 600, 8, b2_dynamicBody );

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PlayerComponent>(pc);
	entity->addComponent<PhysicComponent>(phc);

	_eworld->pushEntity(entity);

	return entity;
}

Entity* EntityFactory::SpawnBlock( float x, float y )
{
	Entity* entity = acquireEntity();
	RenderComponent* rc = acquireComponent<RenderComponent>();
	TransformComponent* tc = acquireComponent<TransformComponent>();
	PhysicComponent* phc = acquireComponent<PhysicComponent>();

	Assets* assets = Locator<Assets>::get();
	rc->LoadFromTexture(&(assets->playertex));
	rc->SetRect(sf::IntRect(64,34,32,34));
	tc->setPosition(x,y);
	phc->body = _physics->CreateRectBody( x, y, 16, 16, b2_staticBody );

	entity->addComponent<RenderComponent>(rc);
	entity->addComponent<TransformComponent>(tc);
	entity->addComponent<PhysicComponent>(phc);

	_eworld->pushEntity(entity);

	return entity;
}
