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
	void process() override;

protected:
	void addEntity(Entity* e) override;
	void removeEntity(Entity* e) override;

	virtual void onEntityAdded(Entity* e) {}
	virtual void onEntityDeleted(Entity* e) {}


	std::unordered_map<eid_t, Entity*> m_entities;
};

#endif
