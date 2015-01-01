#ifndef __ENTITYFACTORY_H__
#define __ENTITYFACTORY_H__

class EntityWorld;
class Entity;

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();

	void setEntityWorld(EntityWorld* eworld);
	Entity* makeTestEntity();

private:
	template<typename ComponentType>
	ComponentType* acquireComponent();

	Entity* acquireEntity();

	EntityWorld* _eworld;
};

#endif
