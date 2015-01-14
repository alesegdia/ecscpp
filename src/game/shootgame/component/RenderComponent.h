#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__

#include <SFML/Graphics.hpp>
#include <ecs/component/Component.h>
#include <core/util/Locator.h>
#include <core/memory/Poolable.h>

struct RenderComponent : public Component
{
	/* Helpers and accesors */
	void loadFromFile(const char* file);
	sf::Sprite* getSprite();
	void SetRect( sf::IntRect rect )
	{
		this->_sprite.setTextureRect( rect );
	}

	/* Poolable interface */
	void cleanUp();

	/* Fields */
	sf::Sprite _sprite;
	sf::Texture _tex;
};

#endif
