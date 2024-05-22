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
    menu.checkSalvataggio("Documentazione\\salvataggio.txt");
    //int diff=m.selezionaDiff();
    menu.display();
    gioco=new Gioco(menu.getDiff());
    if(gioco->partita()) cout<<"Ciao";
    return 0;
} 