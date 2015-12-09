#pragma once

#include <iostream>
#include <ecs/component/ComponentTraits.h>

class Aspect
{
public:
	Aspect() {}
	virtual ~Aspect() {}

	template <typename... Args>
	void all()
	{
		m_allFilter |= ComponentTraits::BuildBits<Args...>();
	}

	template <typename... Args>
	void any()
	{
		m_anyFilter |= ComponentTraits::BuildBits<Args...>();
	}

	template <typename... Args>
	void none()
	{
		m_noneFilter |= ComponentTraits::BuildBits<Args...>();
	}

	bool all( ctflags_t flags )
	{
		return (flags & this->m_allFilter) == m_allFilter;
	}

	bool any( ctflags_t flags )
	{
		return (flags & this->m_anyFilter) != 0;
	}

	bool none( ctflags_t flags )
	{
		return (flags & this->m_noneFilter) == 0;
	}

	bool fits( ctflags_t flags )
	{
		return all(flags) && any(flags) && none(flags);
	}

private:
	ctflags_t m_allFilter = 0;
	ctflags_t m_anyFilter = 0;
	ctflags_t m_noneFilter = 0;

};

