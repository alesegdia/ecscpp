
#pragma once

#include <SFML/Graphics.hpp>

class Spritesheet {
public:
	Spritesheet ();
	virtual ~Spritesheet ();

	bool Prepare( sf::Texture* t, sf::Vector2i size );
	const sf::IntRect& GetFrame( int num_frame );
	sf::Texture* GetTexture();

private:
	sf::Texture* _tex;
	std::vector<sf::IntRect> _rects;
	sf::Vector2i _tileSize;

};

