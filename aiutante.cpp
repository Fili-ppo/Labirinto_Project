#include "aiutante.h"
//Aiutante::Aiutante(){

//}
int Aiutante::interazione(Personaggio *p){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){ //controlla che il giocatore abbia premuto il tasto "1"
        giaInteragito=true;//setta giaInteragito come true, così che i controlli della funzione checkCollisioni() impediscano di ottenere gemme infinite
        p->setGemme(p->getGemme()+50); //aumenta il numero di gemme del giocatore di 50
        return 1;//ritorna 1 così che checkCollisioni() mostri a schermo il dialogo per la risposta corretta
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){ //controlla che il giocatore abbia premuto il tasto 2
        return 2;//ritorna 2 così che checkCollisioni() mostri a schermo il dialogo per l'errore
    }
    else return 0;
}