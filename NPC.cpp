#include "NPC.h"
NPC::NPC(){
    texture=new sf::Texture;
    vivo=true;
}
void NPC::controlloVita(){
    if(vita<=0) vivo=false;
}
