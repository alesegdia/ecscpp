#include "Game.h"
#include <core/game/screen/ScreenManager.h>
#include <sstream>
#include <iostream>

void Game::Create()
{

}

void Game::Run()
{
    sf::Clock frame_clock;
	sf::Time title_timer, fixed_timer, render_timer;

	float render_frames_per_second = 60.f;
	float fixed_frames_per_second = 60.f;

	sf::Time render_time_step = sf::microseconds((1.f/render_frames_per_second)*1e6);
	sf::Time fixed_time_step = sf::microseconds((1.f/fixed_frames_per_second)*1e6);
	sf::Time showfps_time_step = sf::seconds(1.f);
	int fps=0;

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

		// SHOW FPS STEP ************************************
		fps++;
		title_timer += frame_clock.getElapsedTime();
		if( title_timer >= showfps_time_step )
		{
			std::ostringstream oss;
			oss << "fps: " << 1.f/frame_clock.getElapsedTime().asSeconds();
			mWindow.setTitle( oss.str() );
			title_timer = sf::Time::Zero;
			fps = 1;
		}
		// **************************************************

		// FIXED TIME STEP **********************************
		fixed_timer += frame_clock.getElapsedTime();
		while( fixed_timer >= fixed_time_step )
		{
			fixed_timer = fixed_timer - fixed_time_step;
			screenmgr->FixedUpdate();
		}
		// **************************************************

		// RENDER TIME STEP *********************************
        render_timer += frame_clock.getElapsedTime();
        if( render_timer >= render_time_step )
		{
			mWindow.clear();
			screenmgr->Draw(mWindow);
			mWindow.display();
			render_timer = sf::Time::Zero;
		}
		// **************************************************

		// DELTA TIME STEP **********************************
        screenmgr->Update(frame_clock.restart());
        // **************************************************
    }

	screenmgr->UnloadContent();
}
