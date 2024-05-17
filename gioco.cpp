#include "gioco.h"
#include <fstream>
#include <SFML/Graphics.hpp>
Gioco::Gioco(){
    schema.open("labirinto.txt");
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            schema>>tabellone[i][j].su;
            schema>>tabellone[i][j].giu;
            schema>>tabellone[i][j].destra;
            schema>>tabellone[i][j].sinistra;
            schema>>tabellone[i][j].haMercato;
            schema>>tabellone[i][j].haOspedale;
            schema>>tabellone[i][j].haCassa;
            schema>>tabellone[i][j].haNemici;
            schema>>tabellone[i][j].haQuiz;
            schema>>tabellone[i][j].haAiutante;
            schema>>tabellone[i][j].haCasino;
            schema>>tabellone[i][j].haMiniboss;
            schema>>tabellone[i][j].numNemici;
        }
    }
}
void Gioco::attacca(Nemico *n, Arma *a){
    if(a->sprite.getGlobalBounds().intersects(n->sprite.getGlobalBounds())){
        a->faiDanno(n);
    }
}