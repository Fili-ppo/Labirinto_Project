#include <SFML/Graphics.hpp>
#include <iostream>
#include "personaggio.h"
#include "menu.h"
int main(void){
    Personaggio p;
    Menu m(&p);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Joystick", sf::Style::Fullscreen);
    p.crea("zelda.png");
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
        m.update(&p);
        m.display(&window); //da vedere 
        window.clear();
        window.draw(p.sprite);
        window.display();
    }
    return 0;
}