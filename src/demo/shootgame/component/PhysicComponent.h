
#pragma once

#include <ecs/component/Component.h>
#include <Box2D/Box2D.h>


struct PhysicComponent : public Component
{
	b2Body* body;
	void cleanUp() override;
};

