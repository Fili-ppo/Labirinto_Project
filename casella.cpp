#include "casella.h"
Casella::Casella(){

}
void Casella::inizializza(){ //controlla gli attributi della casella e a seconda di quelli decide che tipo di npc è presente in questa casella
    if(haAiutante) npc=new Aiutante();
    else if(haCasino) npc=new Casino();
    else if(haMercato) npc=new Mercante();
    else if(haMiniboss) npc=new Nemico(20);
    else if(haNemici) npc=new Nemico[2];
    else if(haOspedale) npc=new Medico();
    else if(haQuiz) npc=new Quiz();
}