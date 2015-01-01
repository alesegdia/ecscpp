#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include <core/game/screen/Screen.h>
#include <core/assets/AssetHolder.h>
#include <ecs/system/EntityProcessingSystem.h>
#include "../entity/EntityFactory.h"
#include "../component/ComponentPools.h"
#include "../entity/GameWorld.h"
#include "../system/RenderingSystem.h"
#include "../system/PlayerControllerSystem.h"

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
		GameWorld			_eworld;

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
