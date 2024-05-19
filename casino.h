#ifndef CASINO_H
#define CASINO_H
#include "NPC.h"
class Casino: public NPC{
    private:

    public:
        Casino():NPC(){/*texture->loadFromFile("Images\\casino.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);*/};
        void scommetti();
        int scommessa=rand()%101;
};
#endif