#ifndef MENU_H
#define MENU_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
class Menu{
    private:
        sf::RenderWindow *finestra;
    public:
        Menu();
        void update();
};
#endif