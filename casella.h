#ifndef CASELLA_H
#define CASELLA_H
#include "NPC.h"
#include "aiutante.h"
#include "casino.h"
#include "cassa.h"
#include "medico.h"
#include "quiz.h"
#include "nemico.h"
#include "mercante.h"
class Casella{
    private:
        
    public:
        bool su;
        bool giu;
        bool destra;
        bool sinistra;
        bool haMercato;
        bool haOspedale;
        bool haCassa;
        bool haNemici;
        bool haQuiz;
        bool haAiutante;
        bool haCasino;
        bool haMiniboss;
        Casella();
        NPC *npc;
        sf::Texture textCassa;
        sf::Sprite cassa;
        sf::RectangleShape porta[4]; //0 su, 1 giu, 2 destra, 3 sinistra
        sf::Texture sfondo;
        sf::Sprite sfondo2;
        void inizializza();
        
};
#endif