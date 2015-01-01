#ifndef __ENTITYFACTORY_H__
#define __ENTITYFACTORY_H__

class EntityManager;
class Entity;

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();

	void setEntityManager(EntityManager* emgr);
	Entity* makeTestEntity();

private:
	template<typename ComponentType>
	ComponentType* acquireComponent();

	Entity* acquireEntity();

	EntityManager* _emgr;
};

#endif
