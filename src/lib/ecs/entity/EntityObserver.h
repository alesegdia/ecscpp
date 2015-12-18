#ifndef __ENTITYOBSERVER_H__
#define __ENTITYOBSERVER_H__

#include "Entity.h"

/**
 * @brief The IEntityObserver interface is used for an object that needs
 * to be notified about entity operations
 */
class IEntityObserver
{
public:
	virtual ~IEntityObserver() {	}

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
	 * @brief called when a component has been attached to or removed from an entity
	 * @param e the entity
	 */
	virtual void entityChanged(Entity* e) = 0 ;
};

#endif
