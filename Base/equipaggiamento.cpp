#include "equipaggiamento.h"
Equipaggiamento::Equipaggiamento(){

}
void Equipaggiamento::crea(std::string file){
    texture.loadFromFile(file);
    sprite.setScale(0.1,0.1);
    sprite.setTexture(texture);
}