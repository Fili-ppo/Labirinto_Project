#ifndef GIOCO_H
#define GIOCO_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
#include "nemico.h"
#include <SFML/Graphics.hpp>
#include <fstream>
class Gioco{
    private:
        Casella tabellone[7][7];
        std::ifstream schema;
        std::ifstream sfondi;
        
    public:
        void attacca(Nemico *n, Arma *a);
};
#endif