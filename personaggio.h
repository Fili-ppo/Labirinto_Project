#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Personaggio{
    protected:
        int vita;
        int gemme;
    public:
        Personaggio();
        bool vivo;
        Texture *texture; //apparenza del pg
        Sprite sprite; //pg vero e proprio
        Clock invincibile; //aggiunge i frame di invincibilità, senza i personaggi verrebbero one shottati (da spostare solo su nemico e eroe)
        int getVita(){return vita;};
        int getGemme(){return gemme;};
        void setVita(int v){vita=v;};
        void setGemme(int g){gemme=g;};
        virtual void aumenta(){};

};

#endif