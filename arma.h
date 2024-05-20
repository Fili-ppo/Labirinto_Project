#ifndef ARMA_H
#define ARMA_H
#include "equipaggiamento.h"
#include "NPC.h"
class Arma: public Equipaggiamento{
    private:
        int danno; //valore di danno fatto dall'arma
    public:
        Arma();
        void faiDanno(NPC *n);
        void setDanno(int d){danno=d;};

};
#endif