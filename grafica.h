#ifndef GRAFICA_H
#define GRAFICA_H
#include <SFML/Graphics.hpp>
#include "giocatore.h"
#include <sstream>
class Grafica{
    private:
        stringstream ssGemme;
        Font font;
        Texture vita, vitaPersa, chiave1, chiavi2[4], textGemme;
    public:
        Grafica();
        void update(Giocatore *g);
        Sprite barraVita[10], chiavi[4], immGemme;
        Text gemme;
        
};
#endif