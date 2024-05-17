#include "quiz.h"
using namespace std;
Quiz::Quiz(){

}
void Quiz::indovinello(){
    string risp;
    string risp1;
    cout<<"ciao avventuriero, per avere delle ricopmpense scegli un numero da 1 a 4 e rispondi al seguente indovinello/n";
    cin>>risp;
    switch (risp){
        case 1:
            cout<<"Un mattone pesa un chilo più mezzo mattone. Quanti kg pesa un mattone?/nA)1Kg /nB)2Kg /nC)3Kg/n";
            cin>>risp1;
            if(risp1=='B'){
                cout<<"complimenti, sei un vero genio! ecco a te la ricompensa";
                //dai ricompensa
            }else {cout<<"risposta sbagliata!! sara' per la prossima";}
        break;
        case 2:
            cout<<"La somma dell'età di cinque ragazzi è 48. Tra 10 anni quale sarà la somma delle loro età?/nA)58 /nB)68 /nC)98/n";
            cin>>risp1;
            if(risp1=='C'){
                cout<<"complimenti, sei un vero genio! ecco a te la ricompensa";
                //dai ricompensa
            }else {cout<<"risposta sbagliata!! sara' per la prossima";}
        break;
        case 3:
            cout<<"Un plotone di soldati è composto da 3 colonne e 15 righe. Le righe sono distanti tra loro di 2 metri. Quanto è lungo il plotone?/nA)1Kg /nB)2Kg /nC)3Kg/n";
            cin>>risp1;
            if(risp1=='B'){
                cout<<"complimenti, sei un vero genio! ecco a te la ricompensa";
                //dai ricompensa
            }else {cout<<"risposta sbagliata!! sara' per la prossima";}
        break;
        case 4:
            cout<<"Il signor Rossi ha 4 figlie. Ogni figlia ha un fratello. Quanti figli ha in tutto?/nA)8/nB)4/nC)5/n";
            cin>>risp1;
            if(risp1=='C'){
                cout<<"complimenti, sei un vero genio! ecco a te la ricompensa";
                //dai ricompensa
            }else {cout<<"risposta sbagliata!! sara' per la prossima";}
        break;

    }
}