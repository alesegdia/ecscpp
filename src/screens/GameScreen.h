#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "AssetHolder.h"
#include "EntityProcessingSystem.h"
#include "EntityFactory.h"
#include "ComponentPools.h"
#include "EntityManager.h"
#include "RenderingSystem.h"
#include "PlayerControllerSystem.h"

class GameScreen : public Screen
{
    public:
        GameScreen();
        ~GameScreen();

        void LoadContent(); // new bob; new world;
        void UnloadContent();

        void HandleInput(sf::RenderWindow &window);
        void Update(sf::Time delta);
        void Draw(sf::RenderWindow &window);

    private:
    	/* Assets */
    	AssetHolder<sf::Image> _spriteHolder;

		/* Entities */
		EntityFactory 		_efactory;
		EntityManager		_emgr;

		/* Systems */
		RenderingSystem		_rsystem;
		PlayerControllerSystem _pcsys;

		/* Pools */
		CRenderPool			_crenderpool;
		CTransformPool		_ctransfpool;
		CPlayerPool			_cplayerpool;
		EntityPool			_entitypool;

};

#endif // GAMESCREEN_H
