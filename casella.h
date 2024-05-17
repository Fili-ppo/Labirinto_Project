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