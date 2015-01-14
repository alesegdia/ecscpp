#ifndef __TRANSFORMCOMPONENT_H__
#define __TRANSFORMCOMPONENT_H__

#include <SFML/System.hpp>
#include <ecs/component/Component.h>
#include <core/util/Locator.h>

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
