#include "personaggio.h"
Personaggio::Personaggio(){
    
}
void Personaggio::crea(std::string file){
    texture.loadFromFile(file); //carica il png 
    sprite.setScale(0.5,0.5); //imposta la grandezza del personaggio
    sprite.setTexture(texture); //imposta la il png sullo sprite
    //da sostituire con setTextureRect così da poter utilizzare le sprite sheet
}
void Personaggio::prendiDanno(int danno){
    if(invincibile.getElapsedTime().asSeconds()>=3){ //frame di invincibilità
        vita-=danno;
        invincibile.restart();
    }
}
int Personaggio::getVita(){
    return vita;
}
