#ifndef __PLAYERCONTROLLERSYSTEM_H__
#define __PLAYERCONTROLLERSYSTEM_H__

#include "../component/Components.h"
#include <SFML/Window.hpp>

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
		PhysicComponent* phc =
			e->getComponent<PhysicComponent>();

		int dx, dy;
		dx = dy = 0;

		bool left, right, up, down;
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

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
		phc->body->SetLinearVelocity( b2Vec2(dx * PLAYER_SPEED, dy * PLAYER_SPEED) );
	}

private:

	static constexpr float PLAYER_SPEED = 4.f;
};

#endif
