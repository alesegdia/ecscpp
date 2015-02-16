#include <iostream>
#include "ScreenManager.h"
#include "Screen.h"


ScreenManager::~ScreenManager()
{}

void ScreenManager::Initialize(const std::string& name)
{
	ScreenPtr screen = GetScreen(name);
	screen->LoadContent();
	currentScreen = screen;
}

void ScreenManager::LoadScreen(const std::string& name)
{
	ScreenPtr nextScreen( GetScreen( name ) );
    currentScreen->UnloadContent();
    currentScreen.swap(nextScreen);
    currentScreen->SetWindow(_window);
    currentScreen->LoadContent();
}

bool ScreenManager::IsValidScreenName( const std::string& name )
{
	return screenMap.find( name ) == screenMap.end();
}

void ScreenManager::AddScreen(const std::string& name, ScreenPtr screen)
{
	if( IsValidScreenName(name) )
	{
		screen->SetScreenManager( this );
		screenMap.insert( std::make_pair( name, screen ) );
	}
	else
	{
		std::cout << "EXISTING SCREEN WITH NAME " << name << std::endl;
	}
}

ScreenPtr ScreenManager::GetScreen( const std::string& name )
{
	ScreenPtr ret(nullptr);
	if( screenMap.find( name ) != screenMap.end() )
	{
		ret = ScreenPtr( screenMap[name] );
	}
	else
	{
		std::cout << "NO SCREEN WITH NAME " << name << std::endl;
	}
	return ret;
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

void ScreenManager::FixedUpdate()
{
	currentScreen->FixedUpdate();
}

void ScreenManager::Draw(sf::RenderWindow &window)
{
    currentScreen->Draw(window);
}

void ScreenManager::HandleInput(sf::RenderWindow &window)
{
    currentScreen->HandleInput(window);
}

void ScreenManager::HandleEvent(sf::Event &event)
{
    currentScreen->HandleEvent(event);
}

ScreenPtr ScreenManager::GetCurrentScreen()
{
	return currentScreen;
}
