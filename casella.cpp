#include "casella.h"
Casella::Casella(){
    haiVinto=false;
    for(int i=0; i<4; i++){
        //porta[i].setFillColor(sf::Color::Red);
        porta[i].setSize({6.f, 1.f});
        porta[i].setScale(10, 2);
    }
    //colore temporaneo
    porta[0].setFillColor(sf::Color::Green);
    porta[1].setFillColor(sf::Color::Blue);
    porta[2].setFillColor(sf::Color::Red);
    porta[3].setFillColor(sf::Color::Yellow);
    //Posizioni delle porte
    porta[0].setPosition(470.f, 10.f);
    porta[1].setPosition(470.f, 980.f);
    porta[2].setPosition(980.f, 470.f);
    porta[3].setPosition(10.f, 470.f);
    //Rotazione di 90 gradi delle porte verso destra/sinistra
    porta[2].setRotation(90);
    porta[3].setRotation(90);
}
void Casella::inizializza(){ //controlla gli attributi della casella e a seconda di quelli decide che tipo di npc è presente in questa casella
    if(haAiutante) npc=new Aiutante();
    else if(haCasino) npc=new Casino();
    else if(haCassa) npc=new Cassa();
    else if(haMercato) npc=new Mercante();
    else if(haMiniboss) npc=new Nemico(10, 40, "Images\\miniboss.png");
    else if(haNemici) npc=new Nemico(5,20, "Images\\nemico.png");
    else if(haOspedale) npc=new Medico();
    else if(haQuiz) npc=new Quiz();
}
void Casella::update(){
    npc->controlloVita();
    if(npc->vivo==false) haiVinto=true;
}