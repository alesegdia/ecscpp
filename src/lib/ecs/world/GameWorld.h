#ifndef __GameWorld_H__
#define __GameWorld_H__

#include "stdinc.h"
#include <ecs/entity/eid_t.h>
#include <ecs/component/Component.h>
#include <ecs/component/ComponentTraits.h>
#include <ecs/entity/Entity.h>
#include <ecs/system/System.h>
#include <ecs/system/EntityProcessingSystem.h>
#include <assert.h>
#include <core/util/Locator.h>
#include <rztl/pool.h>

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

	GameWorld() { }
	~GameWorld() { }

	void Prepare( int max_eids = 99999 )
	{
		for( int i = 0; i < max_eids; i++ )
		{
			_eidpool.checkIn(i);
		}
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

	void pushSystem(System* s)
	{
		// hace falta la variable? creo que no...
		EntitySystem *eps;

		_systems.push_back(s);
		s->world = this;

		if(eps = dynamic_cast<EntitySystem*>(s))
		{
			_epsystems.push_back(eps);
		}
	}

	static bool IsEntityDead(Entity* e)
	{
		return !e->IsAlive();
	}

	void clearEntities()
	{
		Pool<Entity>* entitypool = Locator<Pool<Entity>>::get();
		for( auto it : _entities )
		{
			if( !it->IsAlive() )
			{
				entitypool->Destroy(it);
				this->notifyDeleted(it);
			}
		}
		_entities.erase(std::remove_if(_entities.begin(), _entities.end(),
					[](Entity* e) { return !e->IsAlive(); }), _entities.end());
	}

	void NotifyAdded(Entity* e)
	{
		for (auto it : _epsystems)
		{
			it->added(e);
		}
	}

	void AddEntityToWorld(Entity* e)
	{
		if( _eidpool.Size() <= 0 )
		{
			printf("NO MORE IDS!!\n");
		}
		else
		{
			eid_t entityID = _eidpool.checkOut();
			e->setEID(entityID);
			//e->world = this;
			this->NotifyAdded(e);
			this->_entities.push_back(e);
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
	EntityVector _entities;
};



#endif
