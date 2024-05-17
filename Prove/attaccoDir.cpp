#include <SFML/Graphics.hpp>
class Player {
public:
    sf::RectangleShape shape;
    sf::RectangleShape sword;
    float movementSpeed;
    bool isAttacking;
    int direction; //0 su, 1 giu, 2 sinistra, 3 destra
    Player(float startX, float startY) {
        shape.setPosition(startX, startY);
        shape.setSize({50.f, 50.f});
        shape.setFillColor(sf::Color::Cyan);

        sword.setSize({60.f, 10.f});
        sword.setFillColor(sf::Color::Yellow);

        movementSpeed = 10.f;
        isAttacking = false;
    }
    void update() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            shape.move(0, -0.1); // Move up
            direction=0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            shape.move(0, 0.1); // Move down
            direction=1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            shape.move(-0.1, 0); // Move left
            direction=2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.move(0.1, 0); // Move right
            direction=3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            isAttacking = true;
            switch(direction){
                case 0: 
                    sword.setRotation(270);
                    sword.setPosition(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y /*- shape.getSize().y*/);
                    break;
                case 1:
                    sword.setRotation(90);
                    sword.setPosition(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y + shape.getSize().y);
                    break;
                case 2:
                    sword.setRotation(180);
                    sword.setPosition(shape.getPosition().x , shape.getPosition().y + shape.getSize().y / 2);
                    break;
                case 3: 
                    sword.setRotation(0);
                    sword.setPosition(shape.getPosition().x+shape.getSize().x, shape.getPosition().y + shape.getSize().y / 2);
                    break;
            }
        } else {
            isAttacking = false;
        }
    }
};
int main() {
    int conta=0;
    sf::RectangleShape shape2;
    shape2.setFillColor(sf::Color::Red);
    shape2.setSize({60.f, 60.f});
    shape2.setPosition(500, 300);
    sf::Clock invin;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
    Player player(400, 300);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        player.update();
        window.clear();
        window.draw(player.shape);
        //if(conta<=10){ //c'è il problema per gli attacchi, vanno aggiunti i frame di invincibilità.
            window.draw(shape2);
        //}
        if (player.isAttacking) {
            window.draw(player.sword);
        }
        if(player.isAttacking==true && player.sword.getGlobalBounds().intersects(shape2.getGlobalBounds())){
            if(invin.getElapsedTime().asSeconds()>3){
                shape2.setFillColor(sf::Color::Blue);
                invin.restart();
            }
        }
        else shape2.setFillColor(sf::Color::Red);
        window.display();
    }
    return 0;
}