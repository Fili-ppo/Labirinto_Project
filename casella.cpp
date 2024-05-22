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
    //inizializzo i bordi/angoli
    for(int i=0; i<4; i++){
        bordi[i].setSize({570, 215}); //se dovessero esserci problemi con collisioni inzializzarli a 215, 570 senza mettere la rotation
        bordi[i].setFillColor(sf::Color::Red);
        angoli[i].setSize({215, 215});
        angoli[i].setFillColor(sf::Color::Red);
    }
    bordi[2].setRotation(90);
    bordi[3].setRotation(90);
    angoli[0].setPosition(0,0);
    angoli[1].setPosition(785, 0);
    angoli[2].setPosition(0, 785);
    angoli[3].setPosition(785, 785);
    bordi[0].setPosition(215, 0);
    bordi[1].setPosition(215, 785);
    bordi[2].setPosition(1000, 215);
    bordi[3].setPosition(215, 215);
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
void Casella::collisioni(Personaggio *p){
    /*while (collideLeft()) // se tocca bordi[0](su) p.sprite.setPosition(p.sprite.getPosition().x, p.sprite.getPosition().y-10 o 20 boh
        pos.x++;
    while (collideRight())
        pos.x--;
    while (collideUp())
        pos.y++;
    while (collideDown())
        pos.y--;*/
    //per gli angoli stessa cosa ma bisogna fare il check
    //se p.getPosition().x è minore di angoli[i].getPosition().x allora....
    //se dovessero esserci problemi con collisioni inzializzarli a 215, 570 senza mettere la rotation
}