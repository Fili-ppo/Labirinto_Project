#ifndef MEDICO_H
#define MEDICO_H
#include "NPC.h"
class Medico: public NPC{
    private:

    public:
        Medico():NPC(){texture->loadFromFile("Images\\medico.png"); sprite.setTexture(*texture);};
        void cura();
};
#endif