#include "menu.h"
Menu::Menu(Personaggio *p){
    p2=*p;
    barra.setFillColor(sf::Color::Yellow);
    barra.setRotation(90);
    barra.setSize({100.f, 20.f});
    barra.setPosition(700, 100);
    p2.sprite.setPosition(700, 200);
}
void Menu::display(sf::RenderWindow *window){
    window->draw(barra);
    window->draw(p2.sprite);
}
void Menu::update(Personaggio *p){
    p2=*p;
}