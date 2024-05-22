#ifndef GIOCO_H
#define GIOCO_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include "arma.h"
#include "nemico.h"
#include "giocatore.h"
#include "grafica.h"
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;
using namespace sf;
class Gioco{
    private:
        RenderWindow *finestra;
        Casella tabellone[7][7];
        ifstream schema;
        ifstream sfondi;
        ifstream dialoghi;
        Clock timer;
        RectangleShape portaFinale;
        bool vittoria;
        Grafica grafica;
    public:
        Gioco(int diff);
        Giocatore player;
        void attacca();
        void disegna();
        bool partita();
        void cambiaStanza();
        void checkCollisioni();
        void checkVittoria();
};
#endif