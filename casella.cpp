#include "casella.h"
Casella::Casella(){
    haiVinto=false;
    for(int i=0; i<4; i++){ //inizializza tutte le porte con le stesse dimensioni
        //porta[i].setFillColor(sf::Color::Red);
        porta[i].setSize({10.f, 1.f});
        porta[i].setScale(20, 2);
    }
    //colore temporaneo
    for(int i=0; i<4; i++){
        porta[i].setFillColor(sf::Color::Transparent);
    }
    //Posizioni delle porte
    porta[0].setPosition(395.f, 10.f);
    porta[1].setPosition(395.f, 990.f);
    porta[2].setPosition(990.f, 395.f);
    porta[3].setPosition(10.f, 395.f);
    //Rotazione di 90 gradi delle porte verso destra/sinistra
    porta[2].setRotation(90);
    porta[3].setRotation(90);
}
void Casella::inizializza(int d){ //controlla gli attributi della casella e a seconda di quelli decide che tipo di npc è presente in questa casella
    if(haAiutante) npc=new Aiutante();
    else if(haCassa) npc=new Cassa();
    else if(haMercato) npc=new Mercante();
    else if(haMiniboss) npc=new Nemico(15, 50, "Images\\miniboss.png");
    else if(haNemici){
        switch(d){
            case 1:
                npc=new Nemico(0,10, "Images\\nemico.png");
                break;
            case 2:
                npc=new Nemico(5,20, "Images\\nemico.png");
                break;
            case 3:
                npc=new Nemico(10,30, "Images\\nemico.png");
        }
    }
    else if(haOspedale) npc=new Medico();
    else if(haQuiz) npc=new Quiz();
    else npc=new NPC();
}
void Casella::update(){
    npc->controlloVita(); //controlla che l'npc sia vivo o no
    if(npc->vivo==false) haiVinto=true; //se l'npc non è vivo, è stato sconfitto e hai vinto in quella singola stanza
}