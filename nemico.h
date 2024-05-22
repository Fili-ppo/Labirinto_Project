#ifndef NEMICO_H
#define NEMICO_H
#include "NPC.h"
class Nemico: public NPC{
    private:
        int danno;
    public:
        Nemico(int d, int v, std::string s):NPC(){danno=d;vita=v;texture->loadFromFile(s);sprite.setTexture(*texture); sprite.setScale(0.4,0.4); sprite.setPosition(500-85, 500-85);};
        void muovi(Personaggio *p);
        int interazione(Personaggio *p);
};
#endif