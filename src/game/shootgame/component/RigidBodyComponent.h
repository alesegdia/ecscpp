
#pragma once

#include <ecs/component/Component.h>
#include <Box2D/Box2D.h>


struct RigidBodyComponent : public Component
{
	b2Body* body;
};

