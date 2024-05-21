#include "NPC.h"
NPC::NPC(){
    texture=new sf::Texture;
    vivo=true;
    vita=1;
    font.loadFromFile("Font\\upheavtt.ttf");
    dialogo.setFont(font);
}
void NPC::controlloVita(){
    if(vita<=0) vivo=false;
}
void NPC::setDialoghi(string s, int n){
    dialoghi[n]<<s;
}
