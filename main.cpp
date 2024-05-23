#include <SFML/Graphics.hpp>
#include <iostream>
#include "giocatore.h"
#include "menu.h"
#include "casella.h"
#include "arma.h"
#include "gioco.h"
int main(void){
    Menu menu;
    Gioco *gioco; //è puntatore così non parte subito
    menu.display(); //mostra i 3 pulsanti per la difficoltà, se il mouse lo tocca setta la difficoltà
    gioco=new Gioco(menu.getDiff()); //inizializza il gioco con la difficoltà selezionata
    if(gioco->partita()) menu.finale(1);
    else menu.finale(0);
    return 0;
} 