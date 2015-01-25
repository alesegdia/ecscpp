#ifndef MYGAME_H
#define MYGAME_H

#include <core/game/Game.h>
#include "Assets.h"

class ShootGame : public Game
{
    public:
        ShootGame() : Game(1024, 768, "ShootGame") {}
        virtual ~ShootGame() {}

        void Create();

    private:

    	Assets assets;
};

#endif // MYGAME_H
