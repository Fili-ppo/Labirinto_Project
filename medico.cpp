#include "medico.h"
#include "giocatore.h"
#include <iostream>
using namespace std;
Medico::Medico(){
    
}
void Medico:: cura(){
    string risp;
    cout<<"hey ciao, hai bisogno di cure?('si'/'no')";
    cin>>risp;
    if(risp=="si"){
        cout<<"non proccuparti, ci penso io!";
        //vita=vita+100;
    } else if(risp=="no"){
        cout<<"ah ok, allora sei nel posto sbalgiato, arrivederci";
    }
}