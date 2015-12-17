
#pragma once

#include <ecs/entity/Entity.h>
#include <ecs/entity/EntityObserver.h>
#include <ecs/system/System.h>
#include <ecs/component/Aspect.h>

class EntitySystem : public System, public EntityObserver {

public:
	EntitySystem ();
	virtual ~EntitySystem ();

    void added(Entity *e);
	void deleted(Entity *e);

    void process() override;

	Aspect& aspect();

protected:

	virtual void addEntity(Entity* e);
    virtual void removeEntity(Entity* e);

private:
	Aspect m_aspect;

};

