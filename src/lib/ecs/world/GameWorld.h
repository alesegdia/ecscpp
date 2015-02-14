#ifndef __GameWorld_H__
#define __GameWorld_H__

#include "stdinc.h"
#include <ecs/entity/eid_t.h>
#include <ecs/component/Component.h>
#include <ecs/component/ComponentFlags.h>
#include <ecs/entity/Entity.h>
#include <ecs/system/System.h>
#include <ecs/system/EntityProcessingSystem.h>
#include <assert.h>

typedef int EntityGroup;

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

	size_t Size()
	{
		return _free.size();
	}

private:
	eid_t _nextKey;
	std::stack<eid_t> _free;
};

class GameWorld
{
public:

	GameWorld()
	{
		for( int i = 0; i < 999999; i++ )
		{
			_eidpool.checkIn(i);
		}
	}
	~GameWorld() { }

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

	void pushSystem(System* s)
	{
		// hace falta la variable? creo que no...
		EntitySystem *eps;

		_systems.push_back(s);

		if(eps = dynamic_cast<EntitySystem*>(s))
		{
			_epsystems.push_back(eps);
		}
	}

	Entity* CreateEntity()
	{
		Entity* ret = NULL;
		if( _eidpool.Size() <= 0 )
		{
			printf("NO MORE IDS!!\n");
		}
		else
		{
			ret = Locator<Pool<Entity>>::get()->Create();
			ret->OnCreate();
			eid_t entityID = _eidpool.checkOut();
			ret->setEID(entityID);
		}
		assert(ret != NULL);
		return ret;
	}

	template<typename ComponentType>
	ComponentType* AcquireComponent()
	{
		return Locator<Pool<ComponentType>>::get()->Create();
	}
	 // llevar a entity como addcomponent y sacar del pool desde alli
	 //

	void NotifyAdded(Entity* e)
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
		for (auto it : _systems)
		{
			it->process();
		}
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
	typedef std::vector<EntitySystem*> EPSystemVector;

	GroupMap _groups;
	EIDPool _eidpool;
	SystemVector _systems;
	EPSystemVector _epsystems;
};



#endif