#ifndef __ENTITYPROCESSINGSYSTEM_H__
#define __ENTITYPROCESSINGSYSTEM_H__

#include <ecs/system/EntitySystem.h>
//#include "ComponentFlags.h"

class EntityProcessingSystem : public EntitySystem
{
public:
	EntityProcessingSystem();
	virtual ~EntityProcessingSystem()=0;

	virtual void process(Entity *e);

	/* System interface */
	void process();

protected:
	void addEntity(Entity* e) override;
	void rmEntity(Entity* e) override;

	virtual void onEntityAdded(Entity* e) {}
	virtual void onEntityDeleted(Entity* e) {}


	std::unordered_map<eid_t, Entity*> _entities;
};

#endif
