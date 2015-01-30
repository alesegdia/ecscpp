#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include <core/game/screen/Screen.h>
#include <ecs/system/EntityProcessingSystem.h>
#include "../entity/EntityFactory.h"
#include "../component/ComponentPools.h"
#include "../component/ComponentPoolHolder.h"
#include "../component/Components.h"
#include "../entity/GameWorld.h"
#include "../system/RenderingSystem.h"
#include "../system/PlayerControllerSystem.h"
#include "../system/PhysicSystem.h"
#include "../physics/Physics.h"
#include "../physics/debugrender.h"

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

    	/* Physics */
    	Physics _physics;

		/* Entities */
		EntityPool 			_entitypool;
		EntityFactory 		_efactory;
		GameWorld			_eworld;
		ComponentPoolHolder _poolholder;

		/* Systems */
		RenderingSystem		_rsystem;
		PlayerControllerSystem _pcsys;
		PhysicSystem _physicsys;
		DebugDraw* _debugDraw;


};

#endif // GAMESCREEN_H
