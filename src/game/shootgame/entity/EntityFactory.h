#ifndef __ENTITYFACTORY_H__
#define __ENTITYFACTORY_H__

class GameWorld;
class Entity;
class Physics;

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();

	void Prepare( GameWorld* eworld, Physics* physics );
	Entity* MakePlayer(float x, float y);
	Entity* SpawnBlock( float x, float y );

	// Entity* SpawnEnemyCircle( float x, float y );
	// Entity* SpawnEnemyDiamond( float x, float y );

private:
	template<typename ComponentType>
	ComponentType* acquireComponent();

	Entity* acquireEntity();

	GameWorld* _eworld;
	Physics* _physics;
};

#endif
