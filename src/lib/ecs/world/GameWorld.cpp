#include "GameWorld.h"

EIDPool::EIDPool()
{
	_nextKey = 0;
}

eid_t EIDPool::checkOut()
{
	eid_t ret;
	if(!_free.empty())
		ret = _free.top();
	else
		ret = _nextKey++;
	_free.pop();
	return ret;
}

void EIDPool::checkIn(eid_t id)
{
	_free.push(id);
}

size_t EIDPool::Size()
{
	return _free.size();
}

GameWorld::GameWorld(int max_eids)
{
	for( int i = 0; i < max_eids; i++ )
	{
		m_eidpool.checkIn(i);
	}
}


GameWorld::~GameWorld() { }

void GameWorld::removeEntity(Entity *entity)
{
	notifyDeleted(entity);
	m_eidpool.checkIn(entity->getEID());
}


void GameWorld::assignGroup(Entity *e, EntityGroup eg)
{
	// _groups[eg].push_back(e);
}


void GameWorld::addSystem(System *s)
{
	// hace falta la variable? creo que no...
	EntitySystem *eps;

	m_systems.push_back(s);

	eps = dynamic_cast<EntitySystem*>(s);
	if( nullptr != eps )
	{
		m_epsystems.push_back(eps);
	}
}

void GameWorld::clearEntities()
{
	Pool<Entity>* entitypool = &m_entityPool;
	for( auto it : m_entities )
	{
		if( !it->isAlive() )
		{
			this->notifyDeleted(it);
			entitypool->Destroy(it);
		}
	}
	m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(),
		[](Entity* e) { return !e->isAlive(); }), m_entities.end());
}


void GameWorld::addEntity(Entity *e)
{
	if( m_eidpool.Size() <= 0 )
	{
		printf("NO MORE IDS!!\n");
	}
	else
	{
		eid_t entityID = m_eidpool.checkOut();
		e->m_eid = entityID;

		this->notifyAdded(e);
		this->m_entities.push_back(e);
	}
}

void GameWorld::notifyAdded(Entity *e)
{
	for (EntitySystem* it : m_epsystems)
	{
		it->entityAdded(e);
	}
}

void GameWorld::notifyDeleted(Entity *e)
{
	for (EntitySystem* it : m_epsystems)
	{
		it->entityDeleted(e);
	}
}


void GameWorld::process()
{
	for (auto it : m_systems)
	{
		it->process();
	}
}


const std::vector<Entity *> &GameWorld::getGroup(EntityGroup eg)
{
	return m_groups[eg];
}
