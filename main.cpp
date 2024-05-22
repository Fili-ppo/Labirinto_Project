#include <SFML/Graphics.hpp>
#include <iostream>
#include "giocatore.h"
#include "menu.h"
#include "casella.h"
#include "arma.h"
#include "gioco.h"
int main(void){
    Menu menu;
    Gioco *gioco;
    menu.display();
    gioco=new Gioco(menu.getDiff());
    if(gioco->partita()) menu.finale(1);
    else menu.finale(0);
    return 0;
} 