#include "personaggio.h"
Personaggio::Personaggio(){
    
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
