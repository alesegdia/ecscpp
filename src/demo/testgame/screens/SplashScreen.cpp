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

#define SHARED_FROM_SCREEN(scr) std::shared_ptr<scr>(new scr())
#define SCREEN2KEY(key, scr) if(sf::Keyboard::isKeyPressed(sf::Keyboard::key)) \
                                ScreenManager::GetInstance().LoadScreen(SHARED_FROM_SCREEN(scr))
#define FUNC2KEY(key,func) if(sf::Keyboard::isKeyPressed(sf::Keyboard::key)) \
                                func
#define isDown(key) sf::Keyboard::isKeyPressed(sf::Keyboard::key)

void SplashScreen::HandleInput(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert))
        ScreenManager::GetInstance().LoadScreen(
            std::shared_ptr<Screen>(new GameScreen()));

    //SCREEN2KEY(T, TitleScreen);

    SCREEN2KEY(T, GameScreen);

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
