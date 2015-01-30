#include "RenderComponent.h"
#include "ComponentPools.h"

void RenderComponent::LoadFromTexture(sf::Texture* tex)
{
	_tex = tex;
	_sprite.setTexture(*_tex);
	_sprite.setPosition(-40,-40);
}

sf::Sprite* RenderComponent::getSprite()
{
	return &_sprite;
}

void RenderComponent::cleanUp()
{
	/* release handle */
	Locator<CRenderPool>::get()->release(getHandler());

	/* self object cleanup */
}
