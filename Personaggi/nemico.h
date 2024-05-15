#ifndef NEMICO_H
#define NEMICO_H
#include "equipaggiamento.h"
#include "NPC.h"
class Nemico: public NPC{
    private:
        Equipaggiamento arma;
};
#endif