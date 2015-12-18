#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <memory>
#include <ecs/entity/EntityObserver.h>

class GameWorld;

/**
 * @brief The System class represents a piece of logic to be executed
 * on each world step. Systems will be executed on insert order, but
 * a scheduer could be done to delegate this task.
 */
class System
{
public:
	System();
	virtual ~System()= 0 ;

	/**
	 * @brief step to be executed
	 */
	virtual void process() ;

};

#endif
