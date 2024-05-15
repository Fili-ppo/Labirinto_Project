#include <SFML/Graphics.hpp>
class Player {
public:
    sf::RectangleShape shape;
    sf::RectangleShape sword;
    float movementSpeed;
    bool isAttacking;
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
        if (sf::Joystick::isConnected(0))
        {
            float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
            float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
            shape.move(x * 0.01f, y * 0.01f);
        }
        if (sf::Joystick::isButtonPressed(0,2)) {
            isAttacking = true;
            sword.setPosition(shape.getPosition().x + shape.getSize().x, shape.getPosition().y + shape.getSize().y / 2);
        } else {
            isAttacking = false;
        }
    }
};
int main() {
    
    sf::RectangleShape shape2;
    int hp2=100;
    sf::RectangleShape hp;
    shape2.setFillColor(sf::Color::Red);
    shape2.setSize({60.f, 60.f});
    shape2.setPosition(500,300);
    hp.setPosition(700,100);
    hp.setSize({10.f, hp2});
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
        if (player.isAttacking) {
            window.draw(player.sword);
        }
        if(player.sword.getGlobalBounds().intersects(shape2.getGlobalBounds())){
            if(invin.getElapsedTime().asSeconds()>3){
                shape2.setFillColor(sf::Color::Blue);
                hp2--;
                hp.setSize({10.f, hp2});
                invin.restart();
            }
        }
        window.display();
    }
    return 0;
}