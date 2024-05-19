#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H
#include <string>
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
class Personaggio{
    private:
        std::string nome;
        int vita;
        sf::Clock invincibile; //aggiunge i frame di invincibilità, senza i personaggi verrebbero one shottati (da spostare solo su nemico e eroe)
    public:
        Personaggio();
        sf::Texture texture; //apparenza del pg
        sf::Sprite sprite; //pg vero e proprio
        void crea(std::string file);
        void prendiDanno(int danno);
        int getVita();

};

#endif