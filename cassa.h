#ifndef CASSA_H
#define CASSA_H
#include "NPC.h"
class Cassa:public NPC{
    private:


    public:
        Cassa():NPC(){texture->loadFromFile("Images\\cassa.png"); sprite.setTexture(*texture); sprite.setScale(0.5,0.5); sprite.setPosition(500-85, 500-85);
                      /*textureE.loadFromFile("Images\\tastoE.png"); tasto.setTexture(textureE); tasto.setScale(0.2, 0.2); tasto.setPosition(200, 200);*/};
        int interazione(Personaggio *p);
        Texture textureAperta;
        //Texture textureE;
        //Sprite tasto;

};
#endif