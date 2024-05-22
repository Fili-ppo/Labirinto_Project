#include "nemico.h"
//Nemico::Nemico(){

//}
void Nemico::muovi(Personaggio *p){
    float x=(p->sprite.getPosition().x-sprite.getPosition().x)/5000;
    float y=(p->sprite.getPosition().y-sprite.getPosition().y)/5000;
    //sprite.setPosition(x,y);
    sprite.move(x, y);
}
int Nemico::interazione(Personaggio *p){
    if(sprite.getGlobalBounds().intersects(p->sprite.getGlobalBounds()) && p->invincibile.getElapsedTime().asSeconds()>3){
        p->setVita(p->getVita()-danno);
        p->invincibile.restart();
    }
    return 0;
}