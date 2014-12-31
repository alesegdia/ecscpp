#ifndef __TRANSFORMCOMPONENT_H__
#define __TRANSFORMCOMPONENT_H__

#include <SFML/System.hpp>
#include "Component.h"
#include "Locator.h"

struct TransformComponent : public Component
{
	/* Helpers and accessors */
	void setPosition(int x, int y);

	/* Poolable interface */
	void cleanUp();

	/* Fields */
	sf::Vector2i _position;
};

#endif
