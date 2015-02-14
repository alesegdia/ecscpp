#include <SFML/Graphics.hpp>
#include <core/game/screen/Screen.h>
#include <core/game/screen/ScreenManager.h>

Screen::Screen()
{
    //ctor
}

void Screen::SetScreenManager( ScreenManager* screenmgr )
{
	this->screenmgr = screenmgr;
}
void Screen::LoadContent()
{

}

void Screen::UnloadContent()
{

}

void Screen::SetWindow(sf::RenderWindow* window)
{
	_window = window;
}

void Screen::HandleEvent(sf::Event& event)
{

}

void Screen::HandleInput(sf::RenderWindow &window)
{

}

void Screen::Update(sf::Time delta)
{

}

void Screen::Draw(sf::RenderWindow &window)
{

}
