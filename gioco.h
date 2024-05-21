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
        sf::RenderWindow *finestra;
        Casella tabellone[7][7];
        std::ifstream schema;
        std::ifstream sfondi;
        std::ifstream dialoghi;
        sf::Clock timer;
        bool vittoria;
        sf::RectangleShape portaFinale;
    public:
        Gioco();
        void attacca();
        void disegna();
        void partita();
        void cambiaStanza();
        void checkCollisioni();
        void checkVittoria();
        Giocatore player;
};
#endif