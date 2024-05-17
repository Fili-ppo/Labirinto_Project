#ifndef NPC_H
#define NPC_H
#include "string"
#include "personaggio.h"
using namespace std;
class NPC: public Personaggio{
    private:
        string *dialoghi; //
    public:
        NPC();
};
#endif