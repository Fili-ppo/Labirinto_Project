#include "NPC.h"
NPC::NPC(){
    texture=new sf::Texture;
    vivo=true;
    giaInteragito=false;
    vita=1;
    font.loadFromFile("Font\\upheavtt.ttf");
    for(int i=0; i<6; i++){
        dialogo[i].setFont(font);
    }
    textureDialogo.loadFromFile("Images\\boxDialogo.png");
    boxDialogo.setTexture(textureDialogo);
    boxDialogo.setScale(0.5, 0.5);
    boxDialogo.setPosition(134, 730);
    textureRisposta[0].loadFromFile("Images\\risposta1.png");
    risposta[0].setTexture(textureRisposta[0]);
    textureRisposta[1].loadFromFile("Images\\risposta2.png");
    textureRisposta[2].loadFromFile("Images\\risposta.png");
    risposta[2].setTexture(textureRisposta[2]);
    risposta[1].setTexture(textureRisposta[1]);
    risposta[0].setScale(0.3, 0.3);
    risposta[1].setScale(0.3, 0.3);
    risposta[2].setScale(0.5, 0.3);
    risposta[0].setPosition(222, 870);
    risposta[1].setPosition(592, 870);
    risposta[2].setPosition(370, 830);
    //setto le pos e le dimensioni dei dialoghi
    for(int i=0; i<6; i++){
        dialogo[i].setScale(0.55, 0.65);
        dialogo[i].setFillColor(sf::Color::Black);
    }
    dialogo[0].setPosition(184, 770);
    dialogo[1].setPosition(290, 800);
    dialogo[2].setPosition(282, 890);
    dialogo[3].setPosition(637, 890);
    dialogo[4].setPosition(385, 850);
    dialogo[5].setPosition(430, 830);
}
void NPC::controlloVita(){
    if(vita<=0) vivo=false;
}
void NPC::setDialoghi(string s, int n){
    dialoghi[n]<<s;
    dialogo[n].setString(dialoghi[n].str());
}
