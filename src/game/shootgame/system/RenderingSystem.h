#ifndef __RENDERINGSYSTEM_H__
#define __RENDERINGSYSTEM_H__

#include <ecs/system/EntityProcessingSystem.h>
#include "../component/ComponentFlags.h"
#include <stdinc.h>

class RenderingSystem : public EntityProcessingSystem
{
public:

	RenderingSystem()
	{
		setFlags(construct_flags<RenderComponent,TransformComponent>::flags);
	}
	~RenderingSystem()
	{

	}

	void process(Entity* e)
	{
		RenderComponent* rc = e->getComponent<RenderComponent>();
		TransformComponent* tc = e->getComponent<TransformComponent>();
		rc->getSprite()->setPosition(tc->_position.x, tc->_position.y);

		_window->draw(*(rc->getSprite()));
	}

	void setWindow(sf::RenderWindow *window)
	{
		_window = window;
	}

private:
	sf::RenderWindow* _window;
};

#endif
