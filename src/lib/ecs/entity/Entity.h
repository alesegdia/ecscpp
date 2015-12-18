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

/**
 * @brief The Entity class represents an alive being in the world made up of components
 */
class Entity
{
public:

	friend class GameWorld;

    Entity();
    ~Entity();

	/**
	 * @brief gets the eid
	 * @return the eid
	 */
    eid_t getEID();

	/**
	 * @brief marks an entity as destroyed
	 */
	void destroy();

	/**
	 * @brief checks if alive
	 * @return
	 */
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

	/**
	 * @brief gets the component flags
	 * @return the component flags
	 */
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
