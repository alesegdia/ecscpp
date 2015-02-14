#include <iostream>
#include "ScreenManager.h"
#include "Screen.h"

ScreenPtr currentScreen;

ScreenManager::~ScreenManager()
{}

void ScreenManager::Initialize(ScreenPtr screen)
{
    currentScreen = screen;
}

void ScreenManager::LoadScreen(ScreenPtr screen)
{
    currentScreen->UnloadContent();
    currentScreen.swap(screen);
    currentScreen->SetWindow(_window);
    currentScreen->LoadContent();
}

void ScreenManager::SetWindow(sf::RenderWindow* window)
{
	_window = window;
}

void ScreenManager::LoadContent()
{
    currentScreen->LoadContent();
}

void ScreenManager::UnloadContent()
{
    currentScreen->UnloadContent();
}

void ScreenManager::Update(sf::Time delta)
{
    currentScreen->Update(delta);
}

void ScreenManager::Draw(sf::RenderWindow &window)
{
    currentScreen->Draw(window);
}

void ScreenManager::HandleInput(sf::RenderWindow &window)
{
    currentScreen->HandleInput(window);
}

ScreenPtr ScreenManager::GetCurrentScreen()
{
	return currentScreen;
}
