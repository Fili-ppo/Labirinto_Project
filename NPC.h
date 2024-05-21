#ifndef NPC_H
#define NPC_H
#include "string"
#include "personaggio.h"
#include <sstream>
using namespace std;
class NPC: public Personaggio{
    protected:
        sf::Font font;
        sf::Texture textureRisposta[3];
        sf::Texture textureDialogo;
    public:
        NPC();
        void controlloVita();
        virtual int interazione(Personaggio *p){return 0;};
        sf::Text dialogo[6];
        stringstream dialoghi[6]; 
        void setDialoghi(string s, int n);
        sf::Sprite risposta[3];
        sf::Sprite boxDialogo;
        bool giaInteragito;
};
#endif