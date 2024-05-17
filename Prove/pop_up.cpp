#include <SFML/Graphics.hpp>
#include <iostream>
#include "personaggio.h"
int main(void){
    Personaggio p;
    Personaggio p2;
    p2.crea("mario.png");
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Joystick", sf::Style::Fullscreen);
    p.crea("zelda.png");
    p2.sprite.setPosition(500, 300);
    sf::RectangleShape tasto;
    tasto.setFillColor(sf::Color::Red);
    tasto.setSize({60.f, 60.f});
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
        window.clear();
        window.draw(p.sprite);
        window.draw(p2.sprite);
        if(p.sprite.getGlobalBounds().intersects(p2.sprite.getGlobalBounds())){
            window.draw(tasto);
        }
        window.display();
    }
    return 0;
}