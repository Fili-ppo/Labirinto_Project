#include "aiutante.h"
//Aiutante::Aiutante(){

//}
int Aiutante::interazione(Personaggio *p){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        giaInteragito=true;
        p->setGemme(p->getGemme()+50);
        return 1;     
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        return 2;
    }
    else return 0;
}