#ifndef __ENTITYOBSERVER_H__
#define __ENTITYOBSERVER_H__

#include "Entity.h"
#include <ecs/component/Component.h>

/**
 * @brief The IEntityObserver interface is used for an object that needs
 * to be notified about entity operations
 */
class EntityObserver
{
public:
	virtual ~EntityObserver() {	}

	/**
	 * @brief called when an entity has been added to the world
	 * @param e the entity
	 */
	virtual void entityAdded(Entity* e) = 0 ;

	/**
	 * @brief called when an entity has been deleted from the world
	 * @param e the entity
	 */
	virtual void entityDeleted(Entity* e) = 0 ;

	/**
	 * @brief notification about a component added to an entity
	 * @param e the entity
	 * @param c the component added
	 */
	virtual void entityComponentAdded(Entity* e, Component* c) = 0 ;

	/**
	 * @brief notification about a component just removed from an entity
	 * @param e the entity
	 * @param c the component removed
	 */
	virtual void entityComponentRemoved(Entity* e, Component* c) = 0 ;

};

#endif
