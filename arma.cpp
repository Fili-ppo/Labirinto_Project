#include "arma.h"
Arma::Arma(){

}
void Arma::faiDanno(NPC *n){
        n->setVita(n->getVita()-danno);
}