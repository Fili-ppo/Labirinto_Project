#ifndef CASSA_H
#define CASSA_H
#include "NPC.h"
class Cassa:public NPC{
    private:


    public:
        Cassa():NPC(){texture->loadFromFile("Images\\cassa.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);};
        int interazione(Personaggio *p){return 0;};
};
#endif