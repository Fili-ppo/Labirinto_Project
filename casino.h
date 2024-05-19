#ifndef CASINO_H
#define CASINO_H
#include "NPC.h"
class Casino: public NPC{
    private:

    public:
        Casino():NPC(){};
        void scommetti();
        int scommessa=rand()%101;
};
#endif