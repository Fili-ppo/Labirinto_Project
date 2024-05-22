#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H
#include <string>
#include "equipaggiamento.h"
#include <SFML/Graphics.hpp>
class Personaggio{
    protected:
        std::string nome;
        int vita;
        int gemme;
    public:
        Personaggio();
        sf::Texture *texture; //apparenza del pg
        sf::Sprite sprite; //pg vero e proprio
        sf::Clock invincibile; //aggiunge i frame di invincibilità, senza i personaggi verrebbero one shottati (da spostare solo su nemico e eroe)
        int getVita(){return vita;};
        void setVita(int v){vita=v;};
        bool vivo;
        void setGemme(int g){gemme=g;};
        int getGemme(){return gemme;};
        virtual void aumenta(){};

};

#endif