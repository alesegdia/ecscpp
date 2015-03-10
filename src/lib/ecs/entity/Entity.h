#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <ecs/component/Component.h>
#include <ecs/component/ComponentTraits.h>
#include <core/util/Locator.h>
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
		vec = new Component*[25];
		_flags = 0;
		alive = true;
	}

	~Entity()
	{
		delete [] vec;
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
		this->_flags |= ComponentTraits::GetFlag<SomeComponent>();
	}

	template <typename SomeComponent>
	void UnsetFlag()
	{
		this->_flags &= ~ComponentTraits::GetFlag<SomeComponent>();
	}

	void OnCreate()
	{
		alive = true;
	}

	template <typename ComponentType>
	void AttachComponent(ComponentType* c)
	{
		vec[ComponentTraits::GetIndex<ComponentType>()] = c;
			SetFlag<ComponentType>();
			c->owner = this;
		//_components.push_back( std::pair<std::type_index,Component*>(typeid(ComponentType),c) );
		// se hará el casting de ComponentType* a Component*? dynamic_cast?
		// tal vez quitar el template y dejar que lo castee automaticamente?
		//_components[std::type_index(typeid(ComponentType))] = c;
		/*
		if( _components.find( typeid(ComponentType) ) == _components.end() )
		{
			_components.insert( std::pair<std::type_index,Component*>(typeid(ComponentType),c) );
		}
		*/
		//_flags |= component_flags<ComponentType>::flags;
	}

	template <typename ComponentType>
	ComponentType* getComponent()
	{
		//auto it = std::find_if(_components.begin(), _components.end(), [](std::pair<std::type_index,Component*> p) -> bool { return p.first == typeid(ComponentType); });
		//return static_cast<ComponentType*>((*it).second);
		//return static_cast<ComponentType*>(_components[typeid(ComponentType)]);
		return static_cast<ComponentType*>(vec[ComponentTraits::GetIndex<ComponentType>()]);
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
		/*
		_flags = 0;
		for(auto it : _components)
		{
			//(it.second)->cleanUp();
			it->cleanUp();
		}
		_components.clear();
		*/
	}

	/* Clear just one component */
	template <typename ComponentType>
	void deleteComponent()
	{
		_flags &= ~(ComponentTraits::GetFlag<ComponentType>());

		/* THIS IS FUCKING EVERYTHING!! */
		// try to apply poolable to component and define it somehow in derived components
		//_components[(typeid(ComponentType))]->cleanUp();

		// clear it from the map? check algorithmic complexity and think if it's worth
		//Locator<Pool<ComponentType>>::get()->Destroy(
		//_components[(typeid(ComponentType))];
	}

	void cleanUp()
	{
		/*
		clearComponents();
		Locator<Pool<Entity>>::get()->Destroy(this);
		*/
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
	bool IsFlagActive()
	{
		return _flags & ComponentTraits::GetFlag<SomeComponent>();
	}

	bool IsAlive()
	{
		return alive;
	}

	std::string name;


private:
	bool alive;
	//std::unordered_map<std::type_index,Component*> _components;
	Component** vec;
	ctflags_t _flags;
	eid_t _eid;
};

typedef Pool<Entity> EntityPool;

#endif
