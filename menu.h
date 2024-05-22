#ifndef MENU_H
#define MENU_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Menu{
    private:
        RenderWindow *finestra;
        
    public:
        Menu();
        void update();
};
#endif