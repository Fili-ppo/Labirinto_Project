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
}
void Giocatore::cambiaStanza(int i, int j){
    pos[0]+=i;
    pos[1]+=j;
}
void Giocatore::usaPozione(){

}
void Giocatore::muovi(){
    if(sf::Joystick::isConnected(0)){
        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX); //PovX per DPad, X per joystick
        float y = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY);
        sprite.move(x * 0.001f, -y * 0.001f);
        if (x > 0) {
            sprite.setTexture(texture[2]); 
        } else if (x <0) {
            sprite.setTexture(texture[3]);
        } else if (y > 0) {
            sprite.setTexture(texture[1]);
        } else if (y < 0) {
            sprite.setTexture(texture[0]);
        }
    }
}