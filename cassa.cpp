#include "cassa.h"
#include <iostream>
//Aiutante::Aiutante(){

//}
int Cassa::interazione(Personaggio *p){
    if(Keyboard::isKeyPressed(Keyboard::E) && giaInteragito==false){
        p->setGemme(p->getGemme()+25);
        textureAperta.loadFromFile("Images\\cassaAperta.png");
        sprite.setTexture(textureAperta);
        giaInteragito=true;
    } 
    return 0;
}