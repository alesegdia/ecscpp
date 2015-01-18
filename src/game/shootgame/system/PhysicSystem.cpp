
#include "PhysicSystem.h"
#include "../component/PhysicComponent.h"

PhysicSystem::PhysicSystem ()
{
	 // ctor
}

PhysicSystem::~PhysicSystem ()
{
	 // dtor
}

void PhysicSystem::Prepare( Physics* physics )
{
	this->physics = physics;
}

void PhysicSystem::process()
{
	physics->GetWorld()->Step(1.f/60.f, 6, 2);
}

void PhysicSystem::addEntity(Entity* e)
{
	// do nothing since body is created in EntityFactory
}

void PhysicSystem::rmEntity(Entity* e)
{
	physics->GetWorld()->DestroyBody( e->getComponent<PhysicComponent>()->body );
}
