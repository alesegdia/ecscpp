
#pragma once

#include <ecs/entity/Entity.h>
#include <ecs/entity/EntityObserver.h>
#include <ecs/system/System.h>

class EntitySystem : public System, public EntityObserver {
public:
	EntitySystem ();
	virtual ~EntitySystem ();

	/* EntityObserver interface */
	void added(Entity *e);
	void deleted(Entity *e);

protected:

	virtual void addEntity(Entity* e);
	virtual void rmEntity(Entity* e);

	void setFlags(ctflags_t flags);
	ctflags_t _flags;


};
