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
	Entity* MakePlayer(float x, float y);
	Entity* SpawnEnemyCircle( float x, float y );
	Entity* SpawnEnemyDiamond( float x, float y );

private:
	template<typename ComponentType>
	ComponentType* acquireComponent();

	Entity* acquireEntity();

	GameWorld* _eworld;
};

#endif
