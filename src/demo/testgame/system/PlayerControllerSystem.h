#ifndef __PLAYERCONTROLLERSYSTEM_H__
#define __PLAYERCONTROLLERSYSTEM_H__

class PlayerControllerSystem : public EntityProcessingSystem
{
public:
	PlayerControllerSystem()
	{
		setFlags(construct_flags<PlayerComponent>::flags);
	}

	void process(Entity *e)
	{
		RenderComponent* rc =
			e->getComponent<RenderComponent>();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rc->getSprite()->move(-1,0);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rc->getSprite()->move(1,0);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rc->getSprite()->move(0,-1);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rc->getSprite()->move(0,1);
		}
	}

private:
};

#endif
