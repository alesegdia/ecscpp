#ifndef __PLAYERCOMPONENT_H__
#define __PLAYERCOMPONENT_H__

#include <ecs/component/Component.h>

struct PlayerComponent : public Component
{
	void cleanUp();
};

#endif
