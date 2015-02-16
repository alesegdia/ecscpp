#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <memory>

class ScreenManager;

class Screen
{
    public:
        Screen();
        virtual ~Screen() {}

		void SetScreenManager( ScreenManager* screenmgr );
        virtual void LoadContent()=0;
        virtual void UnloadContent();
        void SetWindow(sf::RenderWindow* window);

		virtual void HandleEvent(sf::Event& event);
        virtual void HandleInput(sf::RenderWindow &window);
        virtual void Update(sf::Time delta);
        virtual void FixedUpdate();
        virtual void Draw(sf::RenderWindow &window);

    protected:
		sf::RenderWindow* _window;
		ScreenManager* screenmgr;
};

#endif // GAMESCREEN_H
