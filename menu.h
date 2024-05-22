#ifndef MENU_H
#define MENU_H
#include "casella.h"
#include "personaggio.h"
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;
using namespace sf;
class Menu{
    private:
        RenderWindow *finestra;
        int diff;
        bool salvato;
        ifstream salvataggio;
    public:
        Menu();
        int selezionaDiff();
        int getDiff(){return diff;};
        void checkSalvataggio(string s);
        void display();
        void update();
        Texture sfondoT, sconfitta, vittoria, pulsante;
        Font font;
        Text text[3];
        Sprite pulsanti[3], sfondo;
        RectangleShape cursore;
};
#endif