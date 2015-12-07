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
	Entity()
	{
		m_components = new Component*[25];
		m_flags = 0;
		alive = true;
	}

	~Entity()
	{
		delete [] m_components;
	}

	void setEID(eid_t eid)
	{
		m_eid = eid;
	}

	eid_t getEID()
	{
		return m_eid;
	}

	template <typename SomeComponent>
	void SetFlag()
	{
		this->m_flags |= ComponentTraits::GetFlag<SomeComponent>();
	}

	template <typename SomeComponent>
	void UnsetFlag()
	{
		this->m_flags &= ~ComponentTraits::GetFlag<SomeComponent>();
	}

	void OnCreate()
	{
		alive = true;
	}

	template <typename ComponentType>
	void AttachComponent(ComponentType* c)
	{
		m_components[ComponentTraits::GetIndex<ComponentType>()] = c;
		SetFlag<ComponentType>();
		c->owner = this;
	}

	template <typename ComponentType>
	ComponentType* getComponent()
	{
		return static_cast<ComponentType*>(m_components[ComponentTraits::GetIndex<ComponentType>()]);
	}

	ctflags_t getFlags()
	{
		return m_flags;
	}

	bool validateFlags(ctflags_t flags)
	{
		return ((m_flags & flags) == flags);
	}

	/* Clear all components */
	void clearComponents()
	{
	}

	/* Clear just one component */
	template <typename ComponentType>
	void deleteComponent()
	{
		m_flags &= ~(ComponentTraits::GetFlag<ComponentType>());
	}

	void cleanUp()
	{
	}

	void SetActive( bool alive )
	{
		this->alive = alive;
	}

	void Destroy()
	{
		alive = false;
	}

	template <typename SomeComponent>
	bool HasComponent()
	{
		return m_flags & ComponentTraits::GetFlag<SomeComponent>();
	}

	bool IsAlive()
	{
		return alive;
	}

	std::string name;


private:
	bool alive;
	Component** m_components;
	ctflags_t m_flags;
	eid_t m_eid;

};

typedef Pool<Entity> EntityPool;

#endif
