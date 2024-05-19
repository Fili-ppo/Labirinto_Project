#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
#include "pozione.h"
class Giocatore:public Personaggio{
    private:
        int gemmins;
        Pozione *pozione;
        int pos[2]; //i e j della casella in cui si trova
        int direzione;
    public:
        Giocatore();
        Arma spada;
        bool staAttaccando;
        void cambiaStanza(int i, int j); //i e j saranno -1, 0 o 1 a seconda della porta attraversata
        int getI(){return pos[0];};
        int getJ(){return pos[1];};
        void usaPozione();
        void muovi();
        void attacca();
        void cambiaArma(Arma *a);
};
#endif