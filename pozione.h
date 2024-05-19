#ifndef POZIONE_H
#define POZIONE_H
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
class Pozione: public Equipaggiamento{
    private:
        //int tipo; //effetto, 1) cura 2) +attacco ...
    public:
        Pozione();
        sf::Texture texture;
        sf::Sprite sprite;
        virtual void utilizza(){};
};
#endif