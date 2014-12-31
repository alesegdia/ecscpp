#ifndef MYGAME_H
#define MYGAME_H

#include "Game.h"

class Ufofrog : public Game
{
    public:
        Ufofrog() : Game(1360, 768, "BobFury") {}
        virtual ~Ufofrog() {}

        void Create();

    private:
};

#endif // MYGAME_H
