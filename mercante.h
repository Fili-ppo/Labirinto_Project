#ifndef MERCANTE_H
#define MERCANTE_H
#include "NPC.h"
class Mercante: public NPC{
    private:

    public:
        Mercante():NPC(){texture->loadFromFile("Images\\mercante.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);};
};
#endif