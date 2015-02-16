#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <core/game/screen/Screen.h>

typedef std::shared_ptr<Screen> ScreenPtr;
class ScreenManager
{
    public:
        ~ScreenManager();
        //static ScreenManager &GetInstance();

		void AddScreen(const std::string& name, std::shared_ptr<Screen> screen);

        void Initialize(const std::string& name);
        void LoadContent();
        void UnloadContent();
        void SetWindow(sf::RenderWindow* window);

        void HandleInput(sf::RenderWindow &window);
        void HandleEvent(sf::Event& event);
        void Update(sf::Time delta);
        void FixedUpdate();
        void Draw(sf::RenderWindow &window);

		ScreenPtr GetCurrentScreen();
		ScreenPtr GetScreen( const std::string& name );
        void LoadScreen(const std::string& name);
        bool IsValidScreenName( const std::string& name);

    private:
		sf::RenderWindow* _window;
		std::shared_ptr<Screen> currentScreen;
		std::map<std::string, std::shared_ptr<Screen>> screenMap;

};

#endif // SCREENMANAGER_H
