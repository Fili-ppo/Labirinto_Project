#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "personaggio.h"
#include "equipaggiamento.h"
class Giocatore:public Personaggio{
    private:
        int gemmins;
        Equipaggiamento e[3]; //da allargare?
    public:
        //muovi
        //dodge
        //istruzioni da tastiera/controller
};
#endif