#include "casino.h"
#include "giocatore.h"
#include <iostream>
using namespace std;
//Casino::Casino(){

//}
void Casino::scommetti(){
    string risp;
    cout<<"hey ciao caro esploratore, vuoi aumentare il numero delle tue gemme ;) ?(si/no)";
    cin>>risp;
    if(risp=="si"){
        cout<<"ottima scelta amico mio, hai il 5 percento di possibilità di raddoppiare le tue gemme, altrimnti le perderai tutte." ;
            if(scommessa<=5){
                //gemmins=gemmins*2;
                //cout<<"complimenti!! ora hai "<<gemmins<<"gemme!";
            } else {
                //gemmins= 0;
                cout<<"mi dispiace caro, hai perso tutte le tue gemme, sarà per la prossima ;)";
            }
    } else if (risp=="no"){cout<<"ne sei proprio siuro? fossi in te ci ripenserei";}
}