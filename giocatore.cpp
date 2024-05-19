#include "giocatore.h"
Giocatore::Giocatore(){
    pos[0]=6; 
    pos[1]=0;
    texture=new sf::Texture[4];
    texture[0].loadFromFile("Images\\personaggioFronte.png");
    texture[1].loadFromFile("Images\\personaggioRetro.png");
    texture[2].loadFromFile("Images\\personaggioDx.png");
    texture[3].loadFromFile("Images\\personaggioSx.png");
    sprite.setTexture(texture[0]);
    sprite.setScale(0.5,0.5);
    sprite.setPosition(500-85, 500-85);
    spada.texture.loadFromFile("Images\\spada.png");
    spada.sprite.setTexture(spada.texture);
    spada.sprite.setScale(0.7,0.7);
    staAttaccando=false;
}
void Giocatore::cambiaStanza(int i, int j){
    pos[0]+=i;
    pos[1]+=j;
}
void Giocatore::usaPozione(){

}
void Giocatore::muovi(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            sprite.move(0, -0.2); 
            sprite.setTexture(texture[1]);
            direzione=0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sprite.move(0, 0.2);
            sprite.setTexture(texture[0]);
            direzione=1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sprite.move(-0.2, 0);
            sprite.setTexture(texture[3]);
            direzione=2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sprite.move(0.2, 0);
            sprite.setTexture(texture[2]);
            direzione=3;
        }
}
void Giocatore::attacca(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        staAttaccando=true;
        switch(direzione){
            case 0:
                spada.sprite.setRotation(0);
                spada.sprite.setPosition(sprite.getPosition().x+55, sprite.getPosition().y-130);
                break;
            case 1:
                spada.sprite.setRotation(180);
                spada.sprite.setPosition(sprite.getPosition().x+115, sprite.getPosition().y+330);
                break;
            case 2:
                spada.sprite.setRotation(270);
                spada.sprite.setPosition(sprite.getPosition().x-160, sprite.getPosition().y+160);
                break;
            case 3: 
                spada.sprite.setRotation(90);
                spada.sprite.setPosition(sprite.getPosition().x+330, sprite.getPosition().y+100);
                break;
        }
    }
    else staAttaccando=false;
}
void Giocatore::cambiaArma(Arma *a){
    spada=*a;
}