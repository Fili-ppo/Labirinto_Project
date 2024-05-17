#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H
#include <string>
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
class Personaggio{
    private:
        std::string nome;
        int pos[2]; //i e j della casella in cui si trova
        int vita;
        sf::Clock invincibile; //aggiunge i frame di invincibilità, senza i personaggi verrebbero one shottati (da spostare solo su nemico e eroe)
    public:
        Personaggio();
        sf::Texture texture; //apparenza del pg
        sf::Sprite sprite; //pg vero e proprio
        void crea(std::string file);
        void cambiaStanza(int i, int j); //i e j saranno -1, 0 o 1 a seconda della porta attraversata
        void prendiDanno(int danno);
        int getVita();

};

#endif