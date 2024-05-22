#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
class Giocatore:public Personaggio{
    private:
        int gemme; //moneta di scambio del gioco
        int pos[2]; //i e j della casella in cui si trova
        int direzione; //verso dove sta guardando il giocatore
        int chiavi; //necessarie per vincere il gioco
    public:
        Giocatore();
        Arma spada; //arma
        bool staAttaccando; //stato del giocatore
        int getI(){return pos[0];};
        int getJ(){return pos[1];};
        void usaPozione();
        void muovi(); 
        void attacca();
        void cambiaStanza(int i, int j); //i e j saranno -1, 0 o 1 a seconda della porta attraversata
        void aumenta();
        void checkVita(){if(vita<=0) vivo=false;};
        int getChiavi(){return chiavi;};
};
#endif