#include "medico.h"
#include "giocatore.h"
#include <iostream>
using namespace std;
//Medico::Medico(){
    
//}
int Medico::interazione(Personaggio *p){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        giaInteragito=true;
        p->setVita(100);
        return 1;     
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        return 2;
    }
    else return 0;
}