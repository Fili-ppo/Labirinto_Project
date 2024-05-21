#include "gioco.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
Gioco::Gioco(){
    //Creo la finestra e le assegno dimensioni e nome
    finestra=new sf::RenderWindow(sf::VideoMode(1000, 1000), "Labirinto");
    //Assegno la struttura al labirinto
    //da mettere switch case per i documenti da considerare
    schema.open("Documentazione\\labirinto.txt");
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
            schema>>tabellone[i][j].haCasino;
            schema>>tabellone[i][j].haMiniboss;
            //dare in input un valore che permetta di cambiare la vita dei nemicia seconda della difficoltà
            tabellone[i][j].inizializza();
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
                for(int k=0; k<3; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                }
                tabellone[i][j].npc->setDialoghi(ss.str(), 2);
                ss.str("");
                for(int k=0; k<4; k++){
                    dialoghi>>s;
                    ss<<s;
                    ss<<" ";
                }
                tabellone[i][j].npc->setDialoghi(ss.str(), 3);
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
    popUp.loadFromFile("Images\\tastoE.png");
    PopUp.setTexture(popUp);
    PopUp.setScale(0.2,0.2);
    PopUp.setPosition(100, 100);
}
void Gioco::attacca(){ //ok
    if(tabellone[player.getI()][player.getJ()].haNemici || tabellone[player.getI()][player.getJ()].haMiniboss){
        if(tabellone[player.getI()][player.getJ()].npc->invincibile.getElapsedTime().asSeconds()>3){
            if(player.spada.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].npc->sprite.getGlobalBounds()) && player.staAttaccando){
                player.spada.faiDanno(tabellone[player.getI()][player.getJ()].npc);
                tabellone[player.getI()][player.getJ()].npc->invincibile.restart();
            }
        }
    }
}
void Gioco::partita(){
    while(finestra->isOpen()){ //quando la finestra è aperta il gioco continua
        sf::Event azione;
        while(finestra->pollEvent(azione)){
            if(azione.type==sf::Event::Closed) finestra->close(); //se premo la x, fermo il programma e chiudo la finestra
        }
        player.muovi();
        player.attacca();
        attacca();
        tabellone[player.getI()][player.getJ()].update();
        cambiaStanza();
        disegna();
        checkCollisioni();
        finestra->display();
    }
}
void Gioco::disegna(){ //ok
    finestra->draw(tabellone[player.getI()][player.getJ()].sfondo2);
    //4 porte
    if(tabellone[player.getI()][player.getJ()].su) finestra->draw(tabellone[player.getI()][player.getJ()].porta[0]);
    if(tabellone[player.getI()][player.getJ()].giu) finestra->draw(tabellone[player.getI()][player.getJ()].porta[1]);
    if(tabellone[player.getI()][player.getJ()].destra) finestra->draw(tabellone[player.getI()][player.getJ()].porta[2]);
    if(tabellone[player.getI()][player.getJ()].sinistra) finestra->draw(tabellone[player.getI()][player.getJ()].porta[3]);
    //Player
    if(tabellone[player.getI()][player.getJ()].haiVinto==false){
        finestra->draw(tabellone[player.getI()][player.getJ()].npc->sprite);
    }
    if(player.staAttaccando) finestra->draw(player.spada.sprite);
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
void Gioco::checkCollisioni(){ //ok
    if(!tabellone[player.getI()][player.getJ()].haNemici && !tabellone[player.getI()][player.getJ()].haMiniboss){
        if(player.sprite.getGlobalBounds().intersects(tabellone[player.getI()][player.getJ()].npc->sprite.getGlobalBounds())){
            finestra->draw(PopUp);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) tabellone[player.getI()][player.getJ()].npc->interazione();
        }
    }
}