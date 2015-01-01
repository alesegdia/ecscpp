#ifndef MYGAME_H
#define MYGAME_H

#include <core/game/Game.h>

class Ufofrog : public Game
{
    public:
        Ufofrog() : Game(1360, 768, "BobFury") {}
        virtual ~Ufofrog() {}

        void Create();

    private:
};

#endif // MYGAME_H
