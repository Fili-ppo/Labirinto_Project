#include <SFML/Graphics.hpp>
#include <sstream>
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            shape.move(0, -0.1); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            shape.move(0, 0.1); // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-0.1, 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(0.1, 0); // Move right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            isAttacking = true;
            sword.setPosition(shape.getPosition().x + shape.getSize().x, shape.getPosition().y + shape.getSize().y / 2);
        } else {
            isAttacking = false;
        }
    }
};
int main() {
    
    sf::RectangleShape shape2;
    const int hpmax=10;
    int hp2=hpmax;
    int gemme=100;
    sf::Text soldi;
    sf::Font font;
    font.loadFromFile("Font/upheavtt.ttf");
    soldi.setFont(font);
    std::stringstream ss;
    ss<<gemme;
    soldi.setString(ss.str());
    sf::RectangleShape hp[hpmax];
    shape2.setFillColor(sf::Color::Red);
    shape2.setSize({60.f, 60.f});
    shape2.setPosition(500,300);
    for(int i=0; i<hpmax; i++){ //HEALTHBAR
        hp[i].setPosition(500+i*15,100);
        hp[i].setSize({10.f, 10.f});
        hp[i].setFillColor(sf::Color::Red);
    }
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
        window.draw(shape2);
        window.draw(soldi);
        for(int j=0; j<hp2; j++){
            window.draw(hp[j]);
        }

        if (player.isAttacking) {
            window.draw(player.sword);
        }
        if(player.isAttacking==true && player.sword.getGlobalBounds().intersects(shape2.getGlobalBounds())){
            if(invin.getElapsedTime().asSeconds()>1.5){
                shape2.setFillColor(sf::Color::Blue);
                hp2--;
                gemme++;
                ss.str("");
                ss<<gemme;
                soldi.setString(ss.str());
                invin.restart();
            }
        }
        else shape2.setFillColor(sf::Color::Red);
        window.display();
    }
    return 0;
}