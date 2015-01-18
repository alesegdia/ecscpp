
#include "RenderingSystem.h"
#include "../component/Components.h"

RenderingSystem::RenderingSystem ()
{
	setFlags(construct_flags<RenderComponent,TransformComponent>::flags);
}

RenderingSystem::~RenderingSystem ()
{
	 // dtor
}

void RenderingSystem::Prepare( sf::RenderWindow* window )
{
	_window = window;
}

void RenderingSystem::process()
{
	RenderList(RenderComponent::ZORDER_0);
	RenderList(RenderComponent::ZORDER_1);
	RenderList(RenderComponent::ZORDER_2);
}

void RenderingSystem::process(Entity* e)
{
	RenderComponent* rc = e->getComponent<RenderComponent>();
	TransformComponent* tc = e->getComponent<TransformComponent>();
	rc->getSprite()->setPosition(tc->_position.x, tc->_position.y);

	_window->draw(*(rc->getSprite()));
}

void RenderingSystem::RenderList( RenderComponent::ZOrder order )
{
	for( auto it : _renderLists[order] )
	{
		process(it);
	}
}

void RenderingSystem::addEntity(Entity* e)
{
	RenderComponent* rc = e->getComponent<RenderComponent>();
	_renderLists[rc->zorder].push_back(e);
}

void RenderingSystem::rmEntity(Entity* e)
{
	// optimization: use vector and divide steps:
	// 		* step: rmEntity -> annotates entity to remove for each renderlist
	// 		* post step: removes all annotated entities from renderlists
	RenderComponent* rc = e->getComponent<RenderComponent>();
	_renderLists[rc->zorder].remove(e);
}
