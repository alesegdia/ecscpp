#ifndef __PLAYERCONTROLLERSYSTEM_H__
#define __PLAYERCONTROLLERSYSTEM_H__

#include "../component/TransformComponent.h"

class PlayerControllerSystem : public EntityProcessingSystem
{
public:
	PlayerControllerSystem()
	{
		setFlags(construct_flags<PlayerComponent>::flags);
	}

	void process(Entity *e)
	{
		TransformComponent* rc =
			e->getComponent<TransformComponent>();

		int dx, dy;
		dx = dy = 0;

		bool left, right, up, down;
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

		if( (left&&!right) || (!left&&right) )
		{
			dx = (left?-1:1);
		}
		if( (up&&!down) || (!up&&down) )
		{
			dy = (up?-1:1);
		}

		rc->_position.x += dx;
		rc->_position.y += dy;
	}

private:
};

#endif
