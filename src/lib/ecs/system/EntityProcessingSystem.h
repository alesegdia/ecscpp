#ifndef __ENTITYPROCESSINGSYSTEM_H__
#define __ENTITYPROCESSINGSYSTEM_H__

#include <ecs/entity/Entity.h>
#include <ecs/entity/EntityObserver.h>
#include <ecs/system/System.h>
//#include "ComponentFlags.h"

class EntityProcessingSystem : public System, public EntityObserver
{
public:
	EntityProcessingSystem();
	virtual ~EntityProcessingSystem()=0;

	virtual void process(Entity *e);

	/* System interface */
	void process();

	/* EntityObserver interface */
	void added(Entity *e);
	void deleted(Entity *e);

protected:
	void setFlags(ctflags_t flags);
	ctflags_t _flags;

private:
	// data dup with eid
	std::unordered_map<eid_t, Entity*> _entities;
	//EntityWorld* _eworld; //???
};

#endif
