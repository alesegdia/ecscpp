#include "ShootGame.h"
#include <core/game/screen/ScreenManager.h>
#include "screens/SplashScreen.h"
#include "screens/GameScreen.h"

void ShootGame::Create()
{
    boost::shared_ptr<Screen> ptr(new SplashScreen());
    //boost::shared_ptr<Screen> ptr(new GameScreen());

    ScreenManager::GetInstance().Initialize(ptr);
}
