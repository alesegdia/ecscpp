
#pragma once

#include <ecs/entity/EntityWorld.h>
#include "../system/RenderingSystem.h"

class GameWorld : public EntityWorld
{

public:

	void draw()
	{
		this->rs->process();
	}

	void setRenderingSystem( RenderingSystem* rs )
	{
		this->rs = rs;
	}

private:

	System* rs;


};
