#ifndef MERCANTE_H
#define MERCANTE_H
#include "NPC.h"
class Mercante: public NPC{
    private:

    public:
        Mercante():NPC(){texture->loadFromFile("Images\\mercante.png"); sprite.setTexture(*texture);};
};
#endif