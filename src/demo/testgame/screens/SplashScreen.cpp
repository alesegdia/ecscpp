#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <iostream>

#include "SplashScreen.h"
#include <core/game/screen/ScreenManager.h>
#include "GameScreen.h"

SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::LoadContent()
{
    if(!mFont.loadFromFile("Font1.ttf"))
        std::cout << "Could not find specified font" << std::endl;

    mText.setString("Swonie... let Wave");
    mText.setCharacterSize(100);
    mText.setFont(mFont);
}

void SplashScreen::UnloadContent()
{

}

#define isDown(key) sf::Keyboard::isKeyPressed(sf::Keyboard::key)

void SplashScreen::HandleInput(sf::RenderWindow &window)
{
	if( isDown(Space) )
	{
		screenmgr->LoadScreen( "GameScreen" );
	}

    if (isDown(Escape))
        window.close();

}

void SplashScreen::Update(sf::Time delta)
{

}

void SplashScreen::Draw(sf::RenderWindow &window)
{
    window.draw(mText);
}
