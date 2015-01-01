#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <boost/shared_ptr.hpp>
#include <SFML/Graphics.hpp>
#include <core/game/screen/Screen.h>
#include <core/CoreCommon.h>
#include <core/util/Singleton.h>


#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager : public Singleton < ScreenManager >
{
    public:
        ~ScreenManager();
        //static ScreenManager &GetInstance();

        void Initialize(ScreenPtr screen);
        void LoadContent();
        void UnloadContent();
        void SetWindow(sf::RenderWindow* window);

        void HandleInput(sf::RenderWindow &window);
        void Update(sf::Time delta);
        void Draw(sf::RenderWindow &window);

        void LoadScreen(ScreenPtr screen);

    private:
		sf::RenderWindow* _window;

};

#endif // SCREENMANAGER_H
