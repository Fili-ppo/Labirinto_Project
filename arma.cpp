#include "arma.h"
Arma::Arma(){

}
void Arma::faiDanno(Nemico *n){
    n->prendiDanno(danno);
}