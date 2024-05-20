#include "NPC.h"
NPC::NPC(){
    texture=new sf::Texture;
}
void NPC::controlloVita(){
    if(vita<=0) vivo=false;
    else vivo=true;
}
