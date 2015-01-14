#ifndef __ENTITYFACTORY_H__
#define __ENTITYFACTORY_H__

class GameWorld;
class Entity;

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();

	void setEntityWorld(GameWorld* eworld);
	Entity* makeTestEntity();

private:
	template<typename ComponentType>
	ComponentType* acquireComponent();

	Entity* acquireEntity();

	GameWorld* _eworld;
};

#endif
