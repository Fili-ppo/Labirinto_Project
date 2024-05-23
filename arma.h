#ifndef ARMA_H
#define ARMA_H
#include "NPC.h"
class Arma{
    private:
        int danno; //valore di danno fatto dall'arma
    public:
        Arma();
        void faiDanno(NPC *n);
        void setDanno(int d){danno=d;};
        Texture texture;
        Sprite sprite;

};
#endif