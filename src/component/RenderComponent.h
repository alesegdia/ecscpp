#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__

#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Locator.h"
#include "Poolable.h"

struct RenderComponent : public Component
{
	/* Helpers and accesors */
	void loadFromFile(const char* file);
	sf::Sprite* getSprite();

	/* Poolable interface */
	void cleanUp();

	/* Fields */
	sf::Sprite _sprite;
	sf::Texture _tex;
};

#endif
