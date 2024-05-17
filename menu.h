#ifndef MENU_H
#define MENU_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
class Menu{
    private:
        sf::RectangleShape *vita;
        Personaggio p2;
        sf::RectangleShape barra;
    public:
        Menu(Personaggio *p);
        void display(sf::RenderWindow *window);
        void update(Personaggio *p);
};
#endif