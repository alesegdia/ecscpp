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

	friend class GameWorld;

    Entity();
    ~Entity();

    eid_t getEID();

	void destroy();
	bool isAlive();

	template <typename ComponentType>
	inline void attachComponent(ComponentType* c)
    {
        m_components[ComponentTraits::GetIndex<ComponentType>()] = c;
		this->m_flags |= ComponentTraits::GetFlag<ComponentType>();
        c->owner = this;
    }

	template <typename ComponentType>
	inline ComponentType* getComponent()
    {
        return static_cast<ComponentType*>(m_components[ComponentTraits::GetIndex<ComponentType>()]);
    }

    template <typename ComponentType>
	inline void deleteComponent()
    {
		m_flags &= ~ComponentTraits::GetFlag<ComponentType>();
    }

    ctflags_t getFlags();


	std::string name;


private:
	bool alive = true;
	std::vector<Component*> m_components;
	ctflags_t m_flags = 0 ;
	eid_t m_eid;

};

typedef Pool<Entity> EntityPool;

#endif
