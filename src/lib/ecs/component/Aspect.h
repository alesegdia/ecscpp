#pragma once

#include <iostream>
#include <ecs/component/ComponentTraits.h>

/**
 * @brief The Aspect class defines a system aspect that entities
 * will or will not fit, depending on the components the entity
 * have.
 *
 * ALL: the entity must have ALL component bits
 * ANY: the entity must have ANY component bits
 * NONE: the entity must have NONE component bits
 *
 * By default, an empty entity fits an empty aspect
 */
class Aspect
{
public:
	Aspect() {}
	virtual ~Aspect() {}

	/**
	 * @brief checks if an entity flags fit the 'all' bits
	 * @param flags entity flags
	 * @return true if the entity fits this aspect 'all' bits
	 */
	bool all( ctflags_t flags );

	/**
	 * @brief checks if an entity flags fit the 'any' bits
	 * @param flags entity flags
	 * @return true if the entity fits this aspect 'any' bits
	 */
	bool any( ctflags_t flags );

	/**
	 * @brief checks if an entity flags fit the 'none' bits
	 * @param flags entity flags
	 * @return true if the entity fits this aspect 'none' bits
	 */
	bool none( ctflags_t flags );

	/**
	 * @brief checks if an entity flag fits an aspect
	 * @param flags entity flags
	 * @return true if the entity fits this aspect entirely
	 */
	bool fits( ctflags_t flags );

	template <typename... Args>
	/**
	 * @brief add bits to the 'all' filter
	 */
	void all()
	{
		m_allFilter |= ComponentTraits::BuildBits<Args...>();
	}

	template <typename... Args>
	/**
	 * @brief add bits to the 'any' filter
	 */
	void any()
	{
		m_anyFilter |= ComponentTraits::BuildBits<Args...>();
	}

	template <typename... Args>
	/**
	 * @brief add bits to the 'none' filter
	 */
	void none()
	{
		m_noneFilter |= ComponentTraits::BuildBits<Args...>();
	}

	template <typename ComponentType>
	/**
	 * @brief checks if all filter contains a specific component type bit
	 * @return
	 */
	bool hasAll()
	{
		return m_allFilter & ComponentTraits::GetFlag<ComponentType>();
	}

private:
	ctflags_t m_allFilter = 0;
	ctflags_t m_anyFilter = 0;
	ctflags_t m_noneFilter = 0;

};

