#ifndef CASELLA_H
#define CASELLA_H
#include "NPC.h"
#include "aiutante.h"
#include "cassa.h"
#include "medico.h"
#include "quiz.h"
#include "nemico.h"
#include "mercante.h"
using namespace std;
using namespace sf;
class Casella{
    private:
        
    public:
        Casella();
        NPC *npc;
        bool su; //attributi booleani per generare in automatico le caselle
        bool giu;//rappresentano le posizioni, gli eventuali NPC e l'eventuale vittoria contro un nemico
        bool destra;
        bool sinistra;
        bool haMercato;
        bool haOspedale;
        bool haCassa;
        bool haNemici;
        bool haQuiz;
        bool haAiutante;
        bool haMiniboss;
        bool haiVinto;
        //Texture textCassa;
        //Sprite cassa;
        RectangleShape porta[4]; //sono le 4 porte per uscire dalle stanze, a seconda degli attributi di direzione vengono mostrate o meno
        Texture sfondo; //sfondo della stanza
        Sprite sfondo2; //sprite che viene rappresentato per mostrare lo sfondo della stanza
        void inizializza(int d);
        void update();
        
};
#endif