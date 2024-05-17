#include "gioco.h"
Gioco::Gioco(){

}
void Gioco::attacca(Personaggio *p, Arma *a){
    if(a->sprite.getGlobalBounds().intersects(p->sprite.getGlobalBounds())){
        a->faiDanno(p);
    }
}