#include "arma.h"
Arma::Arma(){

}
void Arma::faiDanno(NPC *n){
        n->setVita(n->getVita()-danno); //imposta la vita del nemico che gli viene passato in input come sè stessa - danno dell'arma (toglie vita)
}