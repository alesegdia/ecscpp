#include "Game.h"
#include <core/game/screen/ScreenManager.h>
#include <sstream>

void Game::Create()
{

}

void Game::Run()
{
    mWindow.setFramerateLimit(60);
    sf::Clock frameClock;

    screenmgr->SetWindow( &mWindow );
    Create();

    while(mWindow.isOpen())
    {
		sf::Event event;
		while( mWindow.pollEvent( event ) )
		{
			screenmgr->HandleEvent( event );
		}
		screenmgr->HandleInput(mWindow);

		std::ostringstream oss;
		oss << "fps: " << 1.f/frameClock.getElapsedTime().asSeconds();
        mWindow.setTitle( oss.str() );

        screenmgr->Update(frameClock.restart());

        mWindow.clear();
        screenmgr->Draw(mWindow);
        mWindow.display();
    }

	screenmgr->UnloadContent();
}
