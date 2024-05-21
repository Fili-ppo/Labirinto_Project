#ifndef MEDICO_H
#define MEDICO_H
#include "NPC.h"
class Medico: public NPC{
    private:

    public:
        Medico():NPC(){texture->loadFromFile("Images\\medico.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);};
        int interazione(Personaggio *p);
};
#endif