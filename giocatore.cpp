#include "giocatore.h"
Giocatore::Giocatore(){
    pos[0]=6; 
    pos[1]=0;
}
void Giocatore::cambiaStanza(int i, int j){
    pos[0]+=i;
    pos[1]+=j;
}
void Giocatore::usaPozione(){

}
