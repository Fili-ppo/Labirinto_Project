#ifndef EQUIPAGGIAMENTO_H
#define EQUIPAGGIAMENTO_H
#include <SFML/Graphics.hpp>
#include <string>
class Equipaggiamento{
    private:
        bool equipaggiato; //per vedere se è possibile utilizzarlo o meno
        int costo; //per mercante
    public:
        Equipaggiamento();
        sf::Texture texture;
        sf::Sprite sprite;
        void crea(std::string file);
    
};
#endif