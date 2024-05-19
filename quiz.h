#ifndef QUIZ_H
#define QUIZ_H
#include "NPC.h"
class Quiz: public NPC{
    private:

    public:
        Quiz():NPC(){texture->loadFromFile("Images\\quiz.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);};
        //void indovinello();
};
#endif