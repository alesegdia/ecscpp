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
	// set pools
	Locator<ImageHolder>::set(&_spriteHolder);
	Locator<CRenderPool>::set(&_crenderpool);
	Locator<CTransformPool>::set(&_ctransfpool);
	Locator<CPlayerPool>::set(&_cplayerpool);
	Locator<CPhysicPool>::set(&_cphysicpool);
	Locator<CSpeedPool>::set(&_cspeedpool);
	Locator<EntityPool>::set(&_entitypool);

	_rsystem.setWindow(_window);
	_eworld.setRenderingSystem(&_rsystem);
	_efactory.setEntityWorld(&_eworld);

	_spriteHolder.add("sheet.png");

	_eworld.pushSystem(&_rsystem);
	_eworld.pushSystem(&_pcsys);

	// systems before making entities!!
	_efactory.MakePlayer(300,300);
	_efactory.SpawnEnemyCircle(100,100);
	_efactory.SpawnEnemyDiamond(200,100);
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
