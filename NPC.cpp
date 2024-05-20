#include "NPC.h"
NPC::NPC(){
    texture=new sf::Texture;
    vivo=true;
    vita=1;
}
void NPC::controlloVita(){
    if(vita<=0) vivo=false;
}
