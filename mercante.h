#ifndef MERCANTE_H
#define MERCANTE_H
#include "NPC.h"
class Mercante: public NPC{
    private:

    public:
        Mercante():NPC(){texture->loadFromFile("Images\\mercante.png"); sprite.setTexture(*texture); sprite.setScale(0.4,0.4); sprite.setPosition(500-140, 500-140);};
        int interazione(Personaggio *p);
};
#endif