#include "pozioneVeleno.h"
#include <SFML/Graphics.hpp>
PozioneVeleno::PozioneVeleno(){
    texture.loadFromFile("Images/veleno.png");
    sprite.setTexture(texture);
}
void PozioneVeleno::utilizza(){

}