#include "Ufofrog.h"
#include <core/game/screen/ScreenManager.h>
#include "screens/SplashScreen.h"

void Ufofrog::Create()
{
    boost::shared_ptr<Screen> ptr(new SplashScreen());

    ScreenManager::GetInstance().Initialize(ptr);
}
