#ifndef GIOCO_H
#define GIOCO_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
#include <SFML/Graphics.hpp>
class Gioco{
    private:
        Casella tabellone[7][7];
        Casella extra;
        
    public:
        void attacca(Personaggio *p, Arma *a);
};
#endif