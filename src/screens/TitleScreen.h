#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"

class TitleScreen : public Screen
{
    public:
        TitleScreen();
        ~TitleScreen();

        void LoadContent();
        void UnloadContent();

        void HandleInput(sf::RenderWindow &window);
        void Update(sf::Time delta);
        void Draw(sf::RenderWindow &window);

    private:
        sf::Text mText;
        sf::Font mFont;
};

#endif // TITLESCREEN_H
