
#pragma once

#include <ecs/entity/Entity.h>
#include <ecs/entity/EntityObserver.h>
#include <ecs/system/System.h>

class EntitySystem : public System, public EntityObserver {
public:
	EntitySystem ();
	virtual ~EntitySystem ();

    void added(Entity *e);
	void deleted(Entity *e);

    void process() override;

    template <typename SomeComponent>
    bool hasComponent()
    {
        return m_allFilter & ComponentTraits::GetFlag<SomeComponent>();
    }

protected:

	virtual void addEntity(Entity* e);
    virtual void removeEntity(Entity* e);

    void setFlags(ctflags_t flags);
    ctflags_t getFlags()
    {
        return m_allFilter;
    }

private:
    ctflags_t m_allFilter;


};

