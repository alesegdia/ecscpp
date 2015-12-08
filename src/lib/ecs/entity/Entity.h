#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <ecs/component/Component.h>
#include <ecs/component/ComponentTraits.h>
#include <ecs/entity/eid_t.h>
#include <algorithm>    // std::find_if
#include <typeinfo>

#define COMPONENTMAP_SZ 10

#include <unordered_map>
#include <rztl/pool.h>
template <typename T> using Pool = rztl::Pool<T>;

class Entity
{
public:
    Entity();

    ~Entity();

    // EID accessors
    void setEID(eid_t eid);
    eid_t getEID();

    // events
    void onCreate();

	template <typename SomeComponent>
    void setFlag()
    {
        this->m_flags |= ComponentTraits::GetFlag<SomeComponent>();
    }

	template <typename SomeComponent>
    void unsetFlag()
    {
        this->m_flags &= ~ComponentTraits::GetFlag<SomeComponent>();
    }


    template <typename ComponentType>
    void attachComponent(ComponentType* c)
    {
        m_components[ComponentTraits::GetIndex<ComponentType>()] = c;
        setFlag<ComponentType>();
        c->owner = this;
    }

	template <typename ComponentType>
    ComponentType* getComponent()
    {
        return static_cast<ComponentType*>(m_components[ComponentTraits::GetIndex<ComponentType>()]);
    }

    /* Clear just one component */
    template <typename ComponentType>
    void deleteComponent()
    {
        m_flags &= ~(ComponentTraits::GetFlag<ComponentType>());
    }


    ctflags_t getFlags();

    bool all(ctflags_t flags);

	/* Clear all components */
    void clearComponents();

    void cleanUp();

    void setActive( bool alive );

    void Destroy();

	template <typename SomeComponent>
	bool hasComponent()
	{
        return m_flags & ComponentTraits::GetFlag<SomeComponent>();
	}

    bool isAlive();

	std::string name;


private:
	bool alive;
	std::vector<Component*> m_components;
	ctflags_t m_flags;
	eid_t m_eid;

};

typedef Pool<Entity> EntityPool;

#endif
