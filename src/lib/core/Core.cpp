#include <stdlib.h>
#include <SFML/System.hpp>

namespace core
{
	sf::Clock clock;
	float GetSeconds()
	{
		return core::clock.getElapsedTime().asSeconds();
	}

	int GetMillis()
	{
		return core::clock.getElapsedTime().asMilliseconds();
	}
}
