#ifndef GIOCO_H
#define GIOCO_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
#include "nemico.h"
#include "giocatore.h"
#include <SFML/Graphics.hpp>
#include <fstream>
class Gioco{
    private:
        //sf::RenderWindow *finestra;
        Casella tabellone[7][7];
        std::ifstream schema;
        std::ifstream sfondi;
        
    public:
        Gioco();
        void attacca(Nemico *n, Arma *a);
        void display();
        //void partita();
        Giocatore player;
};
#endif