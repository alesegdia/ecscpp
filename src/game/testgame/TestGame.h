#ifndef MYGAME_H
#define MYGAME_H

#include <core/game/Game.h>

class TestGame : public Game
{
    public:
        TestGame() : Game(1360, 768, "TestGame") {}
        virtual ~TestGame() {}

        void Create();

    private:
};

#endif // MYGAME_H
