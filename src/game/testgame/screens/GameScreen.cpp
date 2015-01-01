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

int currentRes=0;
#define NRES 5
int resolutions[NRES][2] =
{
	{ 1360, 768 },
	{ 1024, 768 },
	{  800, 600 },
	{  640, 480 },
	{  400, 300 }
};
int* getNextRes()
{
	currentRes = (++currentRes)%NRES;
	return resolutions[currentRes];
}
int* getCurrentRes()
{
	return resolutions[currentRes];
}
void setCurrentRes(int cres)
{
	currentRes = cres;
}

void GameScreen::LoadContent()
{
	// set pools
	Locator<ImageHolder>::set(&_spriteHolder);
	Locator<CRenderPool>::set(&_crenderpool);
	Locator<CTransformPool>::set(&_ctransfpool);
	Locator<CPlayerPool>::set(&_cplayerpool);
	Locator<EntityPool>::set(&_entitypool);

	_rsystem.setWindow(_window);
	_eworld.setRenderingSystem(&_rsystem);
	_efactory.setEntityWorld(&_eworld);
	_spriteHolder.add("whiniethefrog.png");
	_spriteHolder.add("nosghy-main-sheet.png");
	_eworld.pushSystem(&_rsystem);
	_eworld.pushSystem(&_pcsys);
	// systems before making entities!!
	_efactory.makeTestEntity();
}

void GameScreen::UnloadContent()
{

}

#define isDown(key) sf::Keyboard::isKeyPressed(sf::Keyboard::key)

void GameScreen::HandleInput(sf::RenderWindow &window)
{
    if(isDown(Escape))
        window.close();
    if(isDown(Num1))
	{
		setCurrentRes(0);
		int* res = getCurrentRes();
		window.create(
				sf::VideoMode(res[0], res[1]),
				"olaqase", sf::Style::Fullscreen);
	}
	else if(isDown(Num2))
	{
		setCurrentRes(1);
		int* res = getCurrentRes();
		window.create(
				sf::VideoMode(res[0], res[1]),
				"olaqase", sf::Style::Fullscreen);
	}
	else if(isDown(Num3))
	{
		setCurrentRes(2);
		int* res = getCurrentRes();
		window.create(
				sf::VideoMode(res[0], res[1]),
				"olaqase", sf::Style::Fullscreen);
	}
	else if(isDown(Num4))
	{
		setCurrentRes(3);
		int* res = getCurrentRes();
		window.create(
				sf::VideoMode(res[0], res[1]),
				"olaqase", sf::Style::Fullscreen);
	}
	else if(isDown(Num5))
	{
		setCurrentRes(4);
		int* res = getCurrentRes();
		window.create(
				sf::VideoMode(res[0], res[1]),
				"olaqase", sf::Style::Fullscreen);
	}

}
void GameScreen::Update(sf::Time delta)
{
	_eworld.process();
}

void GameScreen::Draw(sf::RenderWindow &window)
{
	_eworld.draw();

	/*
	int* res = getCurrentRes();
	text.setString(res[0] + "x" + res[1]);
	text.setPosition(0,0);
	//std::cout << res[0] << ", " << res[1] << std::endl;
	mView.setSize(sf::Vector2f(res[0], res[1]));
	mView.setCenter(sf::Vector2f(0,0));
    mView.setViewport(sf::FloatRect(0.f, 0.f, -1.f, -1.f));
    window.setView(mView);
    sprite2->setPosition(-200, -150);
    sprite2->setOrigin(
    		sprite2->getLocalBounds().width/2,
    		sprite2->getLocalBounds().height/2);
    sprite2->rotate(1);
    sprite1->setPosition(-50,-150);
    window.draw(*sprite1);
    window.draw(*sprite2);
    window.draw(text);
    */
}
