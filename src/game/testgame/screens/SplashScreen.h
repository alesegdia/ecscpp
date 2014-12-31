#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"

class SplashScreen : public Screen
{
    public:
        SplashScreen();
        ~SplashScreen();

        void LoadContent();
        void UnloadContent();

        void HandleInput(sf::RenderWindow &window);
        void Update(sf::Time delta);
        void Draw(sf::RenderWindow &window);

    private:
        sf::Text mText;
        sf::Font mFont;
};

#endif // SPLASHSCREEN_H
