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
        RenderWindow *finestraFinale;
        int diff;
        bool salvato;
    public:
        Menu();
        int selezionaDiff();
        int getDiff(){return diff;};
        void display();
        void update();
        void finale(int n);
        Texture sfondoT, sconfitta, vittoria, pulsante, sfondoFinale;
        Font font;
        Text text[3];
        Sprite pulsanti[3], sfondo, schermataFinale;
        RectangleShape cursore;
};
#endif