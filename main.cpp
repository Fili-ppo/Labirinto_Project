#include <SFML/Graphics.hpp>
#include <iostream>
#include "giocatore.h"
#include "menu.h"
#include "casella.h"
#include "arma.h"
#include "gioco.h"
int main(void){
    Menu m;
    Gioco g;
    if(g.partita()) cout<<"Ciao";
    return 0;
} 