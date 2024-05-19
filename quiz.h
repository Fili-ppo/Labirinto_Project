#ifndef QUIZ_H
#define QUIZ_H
#include "NPC.h"
class Quiz: public NPC{
    private:

    public:
        Quiz():NPC(){texture->loadFromFile("Images\\quiz.png"); sprite.setTexture(*texture);};
        //void indovinello();
};
#endif