#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__

#include <SFML/Graphics.hpp>
#include <ecs/component/Component.h>
#include <core/util/Locator.h>
#include <core/memory/Poolable.h>

struct RenderComponent : public Component
{
	enum ZOrder {
		ZORDER_0 = 0,
		ZORDER_1,
		ZORDER_2
	};

	static constexpr int NUM_ZORDERS = 3;

	/* Helpers and accesors */
	void LoadFromTexture(sf::Texture* tex);
	sf::Sprite* getSprite();
	void SetRect( sf::IntRect rect )
	{
		this->_sprite.setTextureRect( rect );
	}

	/* Poolable interface */
	void cleanUp();

	/* Fields */
	sf::Sprite _sprite;
	sf::Texture* _tex;
	ZOrder zorder = ZORDER_1;
};

#endif
