#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <ecs/component/Component.h>
#include <ecs/component/ComponentFlags.h>
#include <core/memory/Pool.h>
#include <core/memory/Poolable.h>
#include <core/util/Locator.h>
#include <ecs/entity/eid_t.h>

#define COMPONENTMAP_SZ 10

class Entity : public Poolable
{
public:
	Entity()
	{
		_flags = 0;
		_components.rehash(COMPONENTMAP_SZ);
	}
	~Entity()
	{

	}

	void setEID(eid_t eid)
	{
		_eid = eid;
	}

	eid_t getEID()
	{
		return _eid;
	}

	template <typename SomeComponent>
	void SetFlag()
	{
		this->_flags |= component_flags<SomeComponent>::flags;
	}

	template <typename SomeComponent>
	void UnsetFlag()
	{
		this->_flags &= ~component_flags<SomeComponent>::flags;
	}

	void OnCreate()
	{
		SetFlag<AliveComponent>();
		SetFlag<ActiveComponent>();
	}

	template <typename ComponentType>
	void addComponent(ComponentType* c)
	{
		// se har� el casting de ComponentType* a Component*? dynamic_cast?
		// tal vez quitar el template y dejar que lo castee automaticamente?
		_components[std::type_index(typeid(ComponentType))] = c;
		SetFlag<ComponentType>();
		//_flags |= component_flags<ComponentType>::flags;
	}

	template <typename ComponentType>
	ComponentType* getComponent()
	{
		return static_cast<ComponentType*>(_components[std::type_index(typeid(ComponentType))]);
	}

	ctflags_t getFlags()
	{
		return _flags;
	}

	bool validateFlags(ctflags_t flags)
	{
		return ((_flags & flags) == flags);
	}

	/* Clear all components */
	void clearComponents()
	{
		_flags = 0;
		for(auto it : _components)
		{
			(it.second)->cleanUp();
		}
		_components.clear();
	}

	/* Clear just one component */
	template <typename ComponentType>
	void deleteComponent()
	{
		_flags &= ~(component_flags<ComponentType>::flags);

		/* THIS IS FUCKING EVERYTHING!! */
		// try to apply poolable to component and define it somehow in derived components
		_components[std::type_index(typeid(ComponentType))]->cleanUp();

		// clear it from the map? check algorithmic complexity and think if it's worth
		Locator<Pool<ComponentType>>::get()->release(
			_components[std::type_index(typeid(ComponentType))]->getHandler());
	}

	void cleanUp()
	{
		clearComponents();
		Locator<Pool<Entity>>::get()->release(_poolHandler);
	}

	void SetActive( bool active )
	{
		if( active ) SetFlag<ActiveComponent>();
		else UnsetFlag<ActiveComponent>();
	}

	void Destroy()
	{
		UnsetFlag<AliveComponent>();
	}

	template <typename SomeComponent>
	bool IsFlagActive()
	{
		return _flags & component_flags<SomeComponent>::flags;
	}

	bool IsAlive()
	{
		return IsFlagActive<AliveComponent>();
	}

	bool IsActive()
	{
		return IsFlagActive<ActiveComponent>();
	}


private:
	std::unordered_map<std::type_index,Component*> _components;
	ctflags_t _flags;
	eid_t _eid;
};

typedef Pool<Entity> EntityPool;

#endif
