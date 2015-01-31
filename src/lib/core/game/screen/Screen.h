#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <boost/shared_ptr.hpp>


class Screen
{
    public:
        Screen();
        virtual ~Screen() {}

        virtual void LoadContent()=0;
        virtual void UnloadContent();
        void SetWindow(sf::RenderWindow* window);

		virtual void HandleEvent(sf::Event& event);
        virtual void HandleInput(sf::RenderWindow &window);
        virtual void Update(sf::Time delta);
        virtual void Draw(sf::RenderWindow &window);

    protected:
		sf::RenderWindow* _window;
    private:
};

#endif // GAMESCREEN_H
