

#pragma once

#include <SFML/Graphics.hpp>
#include <core/assets/Animation.h>
#include <core/assets/Spritesheet.h>

class Assets {

public:

	Assets() {

		// TEXTURES
		this->playertex.loadFromFile("playersheet.png");

		// SPRITESHEETS
		this->playersheet.Prepare(&(this->playertex), sf::Vector2i( 3, 3 ));

		// ANIMATIONS
		this->player_stand.Prepare( &playersheet, 1, -1 );
		this->player_stand.SetFrame(0, 0, sf::seconds(1.0f) );
		this->player_duriro.Prepare( &playersheet, 2, -1 );
		this->player_duriro.SetFrame(0, 3, sf::seconds(0.1f) );
		this->player_duriro.SetFrame(1, 6, sf::seconds(0.1f) );
		this->player_walk.Prepare( &playersheet, 8, -1 );
		this->player_walk.SetFrame(0, 0, sf::seconds(0.2f) );
		this->player_walk.SetFrame(1, 1, sf::seconds(0.2f) );
		this->player_walk.SetFrame(2, 4, sf::seconds(0.2f) );
		this->player_walk.SetFrame(3, 1, sf::seconds(0.2f) );
		this->player_walk.SetFrame(4, 0, sf::seconds(0.2f) );
		this->player_walk.SetFrame(5, 2, sf::seconds(0.2f) );
		this->player_walk.SetFrame(6, 5, sf::seconds(0.2f) );
		this->player_walk.SetFrame(7, 2, sf::seconds(0.2f) );

	}

	sf::Texture playertex;
	Spritesheet playersheet;
	Animation player_stand;
	Animation player_duriro;
	Animation player_walk;

};

