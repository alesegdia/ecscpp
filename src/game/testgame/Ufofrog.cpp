#include "Ufofrog.h"
#include "ScreenManager.h"
#include "SplashScreen.h"

void Ufofrog::Create()
{
    boost::shared_ptr<Screen> ptr(new SplashScreen());

    ScreenManager::GetInstance().Initialize(ptr);
}
