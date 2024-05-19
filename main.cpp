#include <SFML/Graphics.hpp>
#include <iostream>
#include "giocatore.h"
#include "casella.h"
#include "arma.h"
#include "gioco.h"
int main(void){
    Gioco g;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Joystick");
    sf::Texture t;
    t.loadFromFile("Images\\stanzaT1.png");
    sf::Sprite sfondo;
    sfondo.setTexture(t);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        g.player.muovi();
        window.clear(sf::Color::White);
        window.draw(sfondo);
        window.draw(g.player.sprite);
        window.display();
    }
    return 0;
} 