#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <core/game/screen/ScreenManager.h>

class Game
{
    public:
        Game(int wWidth, int wHeight, std::string name) :
            mWindow(sf::VideoMode(wWidth, wHeight), name, sf::Style::None),
    		screenmgr( new ScreenManager() ) {}
        virtual ~Game() {}

        void Run();
        virtual void Create();

    private:
        // probably protected
        sf::RenderWindow mWindow;

    protected:
		std::unique_ptr<ScreenManager> screenmgr;
};

#endif // GAME_H
