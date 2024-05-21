#ifndef AIUTANTE_H
#define AIUTANTE_H
#include "NPC.h"
class Aiutante:public NPC{
    private:


    public:
        Aiutante():NPC(){texture->loadFromFile("Images\\aiutante.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);};
        int interazione();
};
#endif