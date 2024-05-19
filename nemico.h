#ifndef NEMICO_H
#define NEMICO_H
#include "NPC.h"
class Nemico: public NPC{
    private:
        int danno;
    public:
        Nemico():NPC(){danno=10;}; //costruttore per creare i nemici normali
        Nemico(int d):NPC(){danno=d;}; //costruttore per creare i miniboss
};
#endif