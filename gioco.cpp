#include "gioco.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
Gioco::Gioco(int diff){
    vittoria=false;
    portaFinale.setFillColor(sf::Color::Transparent);
    portaFinale.setSize({6.f, 60.f});
    portaFinale.setScale(0.1, 6);
    portaFinale.setRotation(315);
    portaFinale.setPosition(600, 150);
    //Creo la finestra e le assegno dimensioni e nome
    finestra=new sf::RenderWindow(sf::VideoMode(1300, 1000), "Labirinto");
    //Assegno la struttura al labirinto
    //da mettere switch case per i documenti da considerare
    switch(diff){
        case 1:
            schema.open("Documentazione\\labirintoEasy.txt");
            break;
        case 2:
            schema.open("Documentazione\\labirintoMedium.txt");
            break;
        case 3:
            schema.open("Documentazione\\labirintoHard.txt");
            break;
    }
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            schema>>tabellone[i][j].su;
            schema>>tabellone[i][j].giu;
            schema>>tabellone[i][j].destra;
            schema>>tabellone[i][j].sinistra;
            schema>>tabellone[i][j].haMercato;
            schema>>tabellone[i][j].haOspedale;
            schema>>tabellone[i][j].haCassa;
            schema>>tabellone[i][j].haNemici;
            schema>>tabellone[i][j].haQuiz;
            schema>>tabellone[i][j].haAiutante;
            schema>>tabellone[i][j].haMiniboss;
            //dare in input un valore che permetta di cambiare la vita dei nemicia seconda della difficoltà
            tabellone[i][j].inizializza(diff);
        }
    }
    schema.close();
    //Assegno i dialoghi alle classi che ne hanno
    //Quiz mercato quiz quiz ospedale aiutante
    string s;
    stringstream ss;
    dialoghi.open("Dialoghi\\dialoghi.txt");
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(tabellone[i][j].haMercato || tabellone[i][j].haAiutante || tabellone[i][j].haOspedale || tabellone[i][j].haQuiz){
                for(int k=0; k<11; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                }
                tabellone[i][j].npc->setDialoghi(ss.str(), 0);
                ss.str("");
                for(int k=0; k<7; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                }
                tabellone[i][j].npc->setDialoghi(ss.str(), 1);
                ss.str("");
                for(int k=0; k<2; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                    tabellone[i][j].npc->setDialoghi(ss.str(), 2+k);
                    ss.str("");
                }
                for(int k=0; k<4; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                }
                tabellone[i][j].npc->setDialoghi(ss.str(), 4);
                ss.str("");
                for(int k=0; k<4; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                }
                tabellone[i][j].npc->setDialoghi(ss.str(), 5);
                ss.str("");
            }
        }
    }
    dialoghi.close();
    //Assegno gli sprite ad ogni stanza
    sfondi.open("Documentazione\\sfondi.txt");
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            string s;
            sfondi>>s;
            tabellone[i][j].sfondo.loadFromFile(s);
            tabellone[i][j].sfondo2.setTexture(tabellone[i][j].sfondo);
        }
    }
    sfondi.close();
}
void Gioco::attacca(){ //ok
    if(tabellone[player.getI()][player.getJ()].haNemici || tabellone[player.getI()][player.getJ()].haMiniboss){
        if(tabellone[player.getI()][player.getJ()].npc->invincibile.getElapsedTime().asSeconds()>3){
            if(player.spada.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].npc->sprite.getGlobalBounds()) && player.staAttaccando){
                player.spada.faiDanno(tabellone[player.getI()][player.getJ()].npc);
                tabellone[player.getI()][player.getJ()].npc->invincibile.restart();
                player.setGemme(player.getGemme()+5);
            }
        }
    }
}
bool Gioco::partita(){
    while(finestra->isOpen() && vittoria==false && player.vivo==true){ //quando la finestra è aperta il gioco continua
        sf::Event azione;
        while(finestra->pollEvent(azione)){
            if(azione.type==sf::Event::Closed) finestra->close(); //se premo la x, fermo il programma e chiudo la finestra
        }
        player.muovi();
        tabellone[player.getI()][player.getJ()].npc->muovi(&player);
        player.attacca();
        attacca();
        tabellone[player.getI()][player.getJ()].update();
        cambiaStanza();
        disegna();
        checkInterazioni();
        tabellone[player.getI()][player.getJ()].collisioni(&player);
        checkVittoria();
        player.checkVita();
        finestra->display();
    }
    return vittoria;
}
void Gioco::disegna(){ //ok
    finestra->draw(tabellone[player.getI()][player.getJ()].sfondo2);
    //Angoli e bordi x collisioni
    for(int i=0; i<4; i++){
        finestra->draw(tabellone[player.getI()][player.getJ()].angoli[i]);
    }
    //4 porte
    if(tabellone[player.getI()][player.getJ()].su) finestra->draw(tabellone[player.getI()][player.getJ()].porta[0]);
    else finestra->draw(tabellone[player.getI()][player.getJ()].bordi[0]);
    if(tabellone[player.getI()][player.getJ()].giu) finestra->draw(tabellone[player.getI()][player.getJ()].porta[1]);
    else finestra->draw(tabellone[player.getI()][player.getJ()].bordi[1]);
    if(tabellone[player.getI()][player.getJ()].destra) finestra->draw(tabellone[player.getI()][player.getJ()].porta[2]);
    else finestra->draw(tabellone[player.getI()][player.getJ()].bordi[2]);
    if(tabellone[player.getI()][player.getJ()].sinistra) finestra->draw(tabellone[player.getI()][player.getJ()].porta[3]);
    else finestra->draw(tabellone[player.getI()][player.getJ()].bordi[3]);
    //Player
    if(tabellone[player.getI()][player.getJ()].haiVinto==false || (tabellone[player.getI()][player.getJ()].haCassa && tabellone[player.getI()][player.getJ()].npc->giaInteragito)){
        finestra->draw(tabellone[player.getI()][player.getJ()].npc->sprite);
    }
    if(player.staAttaccando) finestra->draw(player.spada.sprite);
    if(player.getI()==0 && player.getJ()==6) finestra->draw(portaFinale);
    finestra->draw(player.sprite);
    
}
void Gioco::cambiaStanza(){
    if(timer.getElapsedTime().asSeconds()>2){
        if(player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].porta[0].getGlobalBounds()) && tabellone[player.getI()][player.getJ()].su==true){
            player.cambiaStanza(-1, 0);
            player.sprite.setPosition(500-85, 800);
            timer.restart();
        } 
        if(player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].porta[1].getGlobalBounds()) && tabellone[player.getI()][player.getJ()].giu==true){
            player.cambiaStanza(1, 0);
            player.sprite.setPosition(500-85, 100);
            timer.restart();
        } 
        if(player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].porta[2].getGlobalBounds()) && tabellone[player.getI()][player.getJ()].destra==true){
            player.cambiaStanza(0, 1);
            player.sprite.setPosition(100, 500-85);
            timer.restart();
        } 
        if(player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].porta[3].getGlobalBounds()) && tabellone[player.getI()][player.getJ()].sinistra==true){
            player.cambiaStanza(0, -1);
            player.sprite.setPosition(800, 500-85);
            timer.restart();
        } 
    }
}
void Gioco::checkInterazioni(){ //ok
    if(!tabellone[player.getI()][player.getJ()].haNemici && !tabellone[player.getI()][player.getJ()].haMiniboss && !tabellone[player.getI()][player.getJ()].haCassa){
        if(player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].npc->sprite.getGlobalBounds()) && tabellone[player.getI()][player.getJ()].npc->giaInteragito==false){
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->boxDialogo);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->dialogo[0]);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->dialogo[1]);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->risposta[0]);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->risposta[1]);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->dialogo[2]);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->dialogo[3]);
            if(tabellone[player.getI()][player.getJ()].npc->interazione(&player)==2) finestra->draw(tabellone[player.getI()][player.getJ()].npc->dialogo[5]);
        }
        else if(tabellone[player.getI()][player.getJ()].npc->giaInteragito && player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].npc->sprite.getGlobalBounds())){
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->risposta[2]);
            finestra->draw(tabellone[player.getI()][player.getJ()].npc->dialogo[4]);
        }
    }
    else tabellone[player.getI()][player.getJ()].npc->interazione(&player);
}
void Gioco::checkVittoria(){
    if(player.getI()==0 && player.getJ()==6){
        if(player.sprite.getGlobalBounds().intersects(portaFinale.getGlobalBounds()) && player.getChiavi()==4 ) vittoria=true;
    }
}