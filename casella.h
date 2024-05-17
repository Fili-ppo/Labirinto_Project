#ifndef CASELLA_H
#define CASELLA_H
#include "Personaggi/aiutante.h"
#include "Personaggi/casino.h"
#include "Personaggi/medico.h"
#include "Personaggi/quiz.h"
#include "Personaggi/nemico.h"
#include "Personaggi/mercante.h"
class Casella{
    private:
        bool su;
        bool giu;
        bool destra;
        bool sinistra;
        bool mobile;
        bool haMercato;
        bool haOspedale;
        bool haCassa;
        bool haNemici;
        bool haQuiz;
        bool haAiutante;
        bool haCasino;
        int numNemici;
    public:
        Casella();
        Aiutante a;
        Casino c;
        Medico m;
        Quiz q;
        Nemico n;
        Mercante me;
        
};
#endif