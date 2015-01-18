#include "GameScreen.h"
#include <SFML/System.hpp>
#include <core/util/Locator.h>
#include <core/memory/Pool.h>

GameScreen::GameScreen()
{
}

GameScreen::~GameScreen()
{
    //dtor
}

void GameScreen::LoadContent()
{

	// set services
	Locator<ImageHolder>::set(&_spriteHolder);
	Locator<EntityPool>::set(&_entitypool);
	Locator<Physics>::set(&_physics);

	_rsystem.setWindow(_window);
	_eworld.setRenderingSystem(&_rsystem);
	_efactory.setEntityWorld(&_eworld);

	_spriteHolder.add("sheet.png");
	_spriteHolder.add("bbreaker.png");
	_physics.Prepare();
	_physicsys.Prepare( &_physics );

	_eworld.pushSystem(&_rsystem);
	_eworld.pushSystem(&_pcsys);
	_eworld.pushSystem(&_physicsys);

	_efactory.MakePlayer(300,300);
	for( int i = 0; i < 10; i++ )
	for( int j = 0; j < 10; j++ )
	{
		_efactory.SpawnBlock(200 + i * 32, 200 + j * 32);
	}

	// systems before making entities!!
	_efactory.SpawnEnemyCircle(100,100);
	Entity* e = _efactory.SpawnEnemyDiamond(200,100);

	//_eworld.deleteEntity(e);
}

void GameScreen::UnloadContent()
{

}

#define isDown(key) sf::Keyboard::isKeyPressed(sf::Keyboard::key)

void GameScreen::HandleInput(sf::RenderWindow &window)
{
    if(isDown(Escape))
        window.close();
}
void GameScreen::Update(sf::Time delta)
{
	_eworld.process();
}

void GameScreen::Draw(sf::RenderWindow &window)
{
	_eworld.draw();
}
