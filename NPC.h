#ifndef NPC_H
#define NPC_H
#include "string"
#include "personaggio.h"
#include <sstream>
using namespace std;
using namespace sf;
class NPC: public Personaggio{
    protected:
        Font font;
        Texture textureRisposta[3];
        Texture textureDialogo;
    public:
        NPC();
        bool giaInteragito;
        Text dialogo[6];
        stringstream dialoghi[6]; 
        Sprite risposta[3];
        Sprite boxDialogo;
        void controlloVita();
        void setDialoghi(string s, int n);
        virtual int interazione(Personaggio *p){return 0;};
        virtual void muovi(Personaggio *p){};
};
#endif