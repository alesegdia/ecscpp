#include "TitleScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

TitleScreen::TitleScreen()
{
    //ctor
}

TitleScreen::~TitleScreen()
{
    //dtor
}

void TitleScreen::HandleInput(sf::RenderWindow &window)
{

}

void TitleScreen::LoadContent()
{
    if(!mFont.loadFromFile("Font1.ttf"))
        std::cout << "Could not find specified font" << std::endl;

    mText.setString("Orion: The Landtaker");
    mText.setCharacterSize(100);
    mText.setFont(mFont);
}

void TitleScreen::UnloadContent()
{

}

void TitleScreen::Update(sf::Time delta)
{

}

void TitleScreen::Draw(sf::RenderWindow &window)
{
    window.draw(mText);
}
