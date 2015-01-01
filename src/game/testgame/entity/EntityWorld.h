#ifndef __EntityWorld_H__
#define __EntityWorld_H__

#include "stdinc.h"
#include <ecs/entity/eid_t.h>
#include <ecs/component/Component.h>
#include <ecs/component/ComponentFlags.h>
#include "EntityGroup.h"
#include <ecs/entity/Entity.h>
#include <ecs/system/System.h>
#include <ecs/system/EntityProcessingSystem.h>
#include "../system/RenderingSystem.h"

class EIDPool
{
public:
	EIDPool()
	{
		_nextKey = 0;
	}

	eid_t checkOut()
	{
		eid_t ret;
		if(!_free.empty())
			ret = _free.top();
		else
			ret = _nextKey++;
		_free.pop();
		return ret;
	}

	void checkIn(eid_t id)
	{
		_free.push(id);
	}

private:
	eid_t _nextKey;
	std::stack<eid_t> _free;
};

class EntityWorld
{
public:

	EntityWorld()
	{

	}

	~EntityWorld()
	{

	}


	/* Entity management *************** */
	void deleteEntity(Entity* entity)
	{
		notifyDeleted(entity);
		entity->clearComponents();
		_eidpool.checkIn(entity->getEID());
	}

	void assignGroup(Entity* e, EntityGroup eg)
	{
		// _groups[eg].push_back(e);
	}

	void pushEntity(Entity* entity)
	{
		eid_t entityID = _eidpool.checkOut();
		entity->setEID(entityID);
		notifyAdded(entity);
	}
	/* ********************************* */

	void pushSystem(System* s)
	{
		// hace falta la variable? creo que no...
		EntityProcessingSystem *eps;
		System *rs;

		if(rs = dynamic_cast<RenderingSystem*>(s))
		{
			// think of making a vector of renderingsystems,
			// to enable something like a debug renderer por bboxes
			_rendersystem = s;
		}
		else
		{
			_systems.push_back(s);
		}

		if(eps = dynamic_cast<EntityProcessingSystem*>(s))
		{
			_epsystems.push_back(eps);
		}
	}

	void notifyAdded(Entity* e)
	{
		for (auto it : _epsystems)
		{
			it->added(e);
		}
	}

	void notifyDeleted(Entity* e)
	{
		for (auto it : _epsystems)
		{
			it->deleted(e);
		}
	}

	void process()
	{
		std::cout << "EntityWorld::process()\n";
		for (auto it : _systems)
		{
			std::cout << "Processing a system...\n";
			it->process();
		}
	}

	void draw()
	{
		_rendersystem->process();
	}

	/* Group management **************** */
	const std::vector<Entity*>& getGroup(EntityGroup eg)
	{
		return _groups[eg];
	}
	/* ********************************* */

private:

	/* Groups */
	typedef std::vector<Entity*> EntityVector;
	typedef std::map<EntityGroup, EntityVector> GroupMap;
	typedef std::vector<System*> SystemVector;
	typedef std::vector<EntityProcessingSystem*> EPSystemVector;

	GroupMap _groups;
	EIDPool _eidpool;
	SystemVector _systems;
	EPSystemVector _epsystems;
	System* _rendersystem;
};



#endif
