#ifndef __GameWorld_H__
#define __GameWorld_H__

#include "stdinc.h"
#include <ecs/entity/eid_t.h>
#include <ecs/component/Component.h>
#include <ecs/component/ComponentTraits.h>
#include <ecs/entity/Entity.h>
#include <ecs/system/EntitySystem.h>
#include <ecs/system/System.h>
#include <assert.h>
#include <rztl/pool.h>

typedef int EntityGroup;

class EIDPool
{
public:
	EIDPool();

	eid_t checkOut();

	void checkIn(eid_t id);

	size_t Size();

private:
	eid_t _nextKey;
	std::stack<eid_t> _free;
};

class GameWorld
{

	static constexpr int MAX_ENTITIES = 1000 ;

private:
	Pool<Entity> m_entityPool;

public:

	GameWorld(int max_eids=1000);
	~GameWorld();

	/* Entity management *************** */
	void addEntity(Entity* e);
	void removeEntity(Entity* entity);
	void assignGroup(Entity* e, EntityGroup eg);
	void addSystem(System* s);
	void clearEntities();
	void process();

	template <typename ComponentType>
	void attachComponent(Entity* e, ComponentType* c)
	{

	}

	template <typename ComponentType>
	void removeComponent(Entity* e)
	{

	}

	/* Group management **************** */
	const std::vector<Entity*>& getGroup(EntityGroup eg);
	/* ********************************* */

private:

	void notifyAdded(Entity* e);
	void notifyDeleted(Entity* e);

	/* Groups */
	typedef std::vector<Entity*> EntityVector;
	typedef std::map<EntityGroup, EntityVector> GroupMap;
	typedef std::vector<System*> SystemVector;
	typedef std::vector<EntitySystem*> EPSystemVector;

	GroupMap m_groups;
	EIDPool m_eidpool;
	SystemVector m_systems;
	EPSystemVector m_epsystems;
	EntityVector m_entities;
};



#endif
