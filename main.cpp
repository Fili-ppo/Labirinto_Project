#include <SFML/Graphics.hpp>
#include <iostream>
#include "personaggio.h"
int main(void){
    Personaggio p;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Joystick");
    p.crea("Images/personaggioDx.png");
    sf::Texture t;
    t.loadFromFile("Images/stanza1.png");
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
        if (sf::Joystick::isConnected(0))
        {
            float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
            float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
            p.sprite.move(x * 0.01f, y * 0.01f);
        }
        window.clear(sf::Color::White);
        window.draw(sfondo);
        window.draw(p.sprite);
        window.display();
    }
    return 0;
}