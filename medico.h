#ifndef MEDICO_H
#define MEDICO_H
#include "NPC.h"
class Medico: public NPC{
    private:

    public:
        Medico():NPC(){texture->loadFromFile("Images\\medico.png"); sprite.setTexture(*texture); sprite.setScale(0.4,0.4); sprite.setPosition(500-140, 500-140);};
        int interazione(Personaggio *p);
};
#endif