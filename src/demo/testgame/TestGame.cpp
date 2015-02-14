#include "TestGame.h"
#include <core/game/screen/ScreenManager.h>
#include "screens/SplashScreen.h"

void TestGame::Create()
{
    std::shared_ptr<Screen> ptr(new SplashScreen());

    ScreenManager::GetInstance().Initialize(ptr);
}
