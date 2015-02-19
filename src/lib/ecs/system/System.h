#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <ecs/entity/EntityObserver.h>

class GameWorld;

class System
{
public:
	System();
	virtual ~System()=0;

	virtual void process();
	// EntityObserver interface here?

	GameWorld* world;

};

#endif
