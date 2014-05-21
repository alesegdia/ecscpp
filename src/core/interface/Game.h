#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Game
{
    public:
        Game(int wWidth, int wHeight, std::string name) :
            mWindow(sf::VideoMode(wWidth, wHeight), name, sf::Style::Fullscreen) {}
        virtual ~Game() {}

        void Run();
        virtual void Create();

    private:
        // probably protected
        sf::RenderWindow mWindow;
};

#endif // GAME_H
