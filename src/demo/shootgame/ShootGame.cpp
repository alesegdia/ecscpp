#include "ShootGame.h"
#include <core/game/screen/ScreenManager.h>
#include "screens/SplashScreen.h"
#include "screens/GameScreen.h"

void ShootGame::Create()
{
    boost::shared_ptr<Screen> ptr(new SplashScreen());
    //boost::shared_ptr<Screen> ptr(new GameScreen());

	Locator<Assets>::set(&(this->assets));
    ScreenManager::GetInstance().Initialize(ptr);
}
