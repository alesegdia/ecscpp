#include "Game.h"
#include "ScreenManager.h"

void Game::Create()
{

}

void Game::Run()
{
    Create();
	ScreenManager::GetInstance().SetWindow(&mWindow);
    ScreenManager::GetInstance().LoadContent();
    sf::Clock frameClock;

    mWindow.setFramerateLimit(60);


    while(mWindow.isOpen())
    {
        //sf::Event event;

        ScreenManager::GetInstance().HandleInput(mWindow);
        ScreenManager::GetInstance().Update(frameClock.restart());

        mWindow.clear();
        ScreenManager::GetInstance().Draw(mWindow);
        mWindow.display();
    }

    ScreenManager::GetInstance().UnloadContent();
}
