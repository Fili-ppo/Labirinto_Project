#include "grafica.h"
Grafica::Grafica(){
    font.loadFromFile("Font\\upheavtt.ttf");
    vita.loadFromFile("Images\\cuore.png");
    vitaPersa.loadFromFile("Images\\cuoreNero.png");
    textGemme.loadFromFile("Images\\gemme.png");
    gemme.setFont(font);
    gemme.setPosition(1170, 110);
    for(int i=0; i<10; i++){
        barraVita[i].setTexture(vita);
        barraVita[i].setPosition(1020+26*i, 400);
        barraVita[i].scale(0.2, 0.2);
    }
    chiave1.loadFromFile("Images\\chiaveX.png");
    chiavi2[0].loadFromFile("Images\\chiave_gialla.png");
    chiavi2[1].loadFromFile("Images\\chiave_blu.png");
    chiavi2[2].loadFromFile("Images\\chiave_verde.png");
    chiavi2[3].loadFromFile("Images\\chiave_viola.png");
    for(int i=0; i<4; i++){
        chiavi[i].setTexture(chiave1);
        chiavi[i].setScale(0.05, 0.05);
    }
    chiavi[0].setPosition(1020, 600);
    chiavi[1].setPosition(1170, 600);
    chiavi[2].setPosition(1020, 730);
    chiavi[3].setPosition(1170, 730);
    immGemme.setTexture(textGemme);
    immGemme.setPosition(1020, 100);
    immGemme.setScale(0.2, 0.2);
    gemme.setString("0");
    gemme.setColor(Color::White);
}
void Grafica::update(Giocatore *g){
    ssGemme.str("");
    ssGemme<<g->getGemme();
    gemme.setString(ssGemme.str());
    for(int i=0; i<g->getChiavi(); i++){
        chiavi[i].setTexture(chiavi2[i]);
    }
    for(int i=9; i>(g->getVita()/10); i--){
        barraVita[i].setTexture(vitaPersa);
    }
    for(int i=0; i<(g->getVita()/10); i++){
        barraVita[i].setTexture(vita);
    }
}