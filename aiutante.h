#ifndef AIUTANTE_H
#define AIUTANTE_H
#include "NPC.h"
class Aiutante:public NPC{
    private:


    public:
        Aiutante():NPC(){texture->loadFromFile("Images\\aiutante.png"); sprite.setTexture(*texture);};
};
#endif