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
        sf::Clock timer;
        sf::Texture popUp;
        sf::Sprite PopUp;
    public:
        Gioco();
        void attacca();
        void disegna();
        void partita();
        void cambiaStanza();
        void checkCollisioni();
        Giocatore player;
};
#endif