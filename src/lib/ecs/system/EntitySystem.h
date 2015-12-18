
#pragma once

#include <ecs/entity/Entity.h>
#include <ecs/entity/EntityObserver.h>
#include <ecs/system/System.h>
#include <ecs/component/Aspect.h>

/**
 * @brief The EntitySystem class is a system that performs an operation
 * over a set of entities existing in the world that accepts its aspect
 */
class EntitySystem : public System, public EntityObserver
{
public:
	EntitySystem ();
	virtual ~EntitySystem () ;

	/**
	 * @brief notification about an added entity
	 * @param e the entity added
	 */
	void entityAdded(Entity *e) override ;

	/**
	 * @brief notification about an entity removed
	 * @param e the entity removed
	 */
	void entityDeleted(Entity *e) override ;

	void entityComponentAdded(Entity *e, Component *c) override;
	void entityComponentRemoved(Entity *e, Component *c) override;

	/**
	 * @brief performs a step on all entities
	 */
	void process() override ;

	/**
	 * @brief gets the system aspect
	 * @return a reference to the system aspect
	 */
	Aspect& aspect();

protected:
	/**
	 * @brief performs a step over a single entity
	 * @param e the entity to be processed
	 */
	virtual void process(Entity *e);

	virtual void onEntityAdded(Entity* e);
	virtual void onEntityDeleted(Entity* e);
	virtual void onEntityChanged(Entity* e);

private:
	std::unordered_map<eid_t, Entity*> m_entities;
	Aspect m_aspect;


};

