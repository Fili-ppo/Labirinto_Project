#ifndef NEMICO_H
#define NEMICO_H
#include "NPC.h"
class Nemico: public NPC{
    private:
        int danno;
    public:
        Nemico():NPC(){danno=10;texture->loadFromFile("Images\\nemico.png");sprite.setTexture(*texture);}; //costruttore per creare i nemici normali
        Nemico(int d, string s):NPC(){danno=d;texture->loadFromFile(s);sprite.setTexture(*texture);}; //costruttore per creare i miniboss
};
#endif