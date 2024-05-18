#ifndef CASELLA_H
#define CASELLA_H
#include "aiutante.h"
#include "casino.h"
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
        int numNemici;
        Casella();
        Aiutante a;
        Casino c;
        Medico m;
        Quiz q;
        Nemico n[2];
        Nemico miniboss;
        Mercante me;
        //Si potrebbe anche fare un solo attributo dinamico che a seconda degli attributi viene castato in maniera diversa
        sf::RectangleShape porta[4];
        sf::Texture sfondo;
        sf::Sprite sfondo2;
        
};
#endif