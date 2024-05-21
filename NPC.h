#ifndef NPC_H
#define NPC_H
#include "string"
#include "personaggio.h"
#include <sstream>
using namespace std;
class NPC: public Personaggio{
    private:
        stringstream dialoghi[4]; 
    public:
        NPC();
        void controlloVita();
        virtual void interazione(){};
        sf::Font font;
        sf::Text dialogo;
        void setDialoghi(string s, int n);
};
#endif