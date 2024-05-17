#ifndef ARMA_H
#define ARMA_H
#include "equipaggiamento.h"
#include "nemico.h"
class Arma: public Equipaggiamento{
    private:
        int danno; //valore di danno fatto dall'arma
        int tipo; //da decidere, potrebbe essere 1) spada 2) arco 3)??? 4)??? ...
        //sprite?
    public:
    Arma();
    void faiDanno(Nemico *n);

};
#endif