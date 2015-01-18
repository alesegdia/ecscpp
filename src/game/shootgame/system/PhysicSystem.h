
#pragma once

#include <ecs/system/EntitySystem.h>
#include "../physics/Physics.h"

class PhysicSystem : public EntitySystem {
public:
	PhysicSystem ();
	virtual ~PhysicSystem ();

	void Prepare( Physics* physics );

	void process();

private:

	void addEntity(Entity* e) override;
	void rmEntity(Entity* e) override;

	Physics* physics;

};

