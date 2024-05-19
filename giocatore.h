#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
#include "pozione.h"
class Giocatore:public Personaggio{
    private:
        int gemmins;
        Arma spada;
        Pozione *pozione;
        int pos[2]; //i e j della casella in cui si trova
    public:
        Giocatore();
        void cambiaStanza(int i, int j); //i e j saranno -1, 0 o 1 a seconda della porta attraversata
        int getI(){return pos[0];};
        int getJ(){return pos[1];};
        void usaPozione();
        void muovi();
        //muovi
        //dodge
        //istruzioni da tastiera/controller
};
#endif