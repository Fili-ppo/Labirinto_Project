#include <SFML/Graphics.hpp>
//PER CONTROLLER -- da rivedere
class Character {
public:
    Character(const std::string& textureFile) {
        if (!texture.loadFromFile(textureFile)) {
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    void move(float dx, float dy) {
        sprite.move(dx, dy);
        if (moveCount % 450 == 0) { 
            frame = (frame + 1) % 4;
        }
        moveCount++;
        if (dx > 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 128, 64, 64)); 
        } else if (dx <0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 64, 64, 64));
        } else if (dy > 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 0, 64, 64));
        } else if (dy < 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 192, 64, 64));
        }
    }
    sf::Sprite& getSprite() {
        return sprite;
    }
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int frame = 0;
    int moveCount = 0;
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Joystick");
    Character character("pokemon.png");
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
            float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X); //PovX per DPad, X per joystick
            float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
            character.move(x * 0.001f, -y * 0.001f);
        }
        window.clear();
        window.draw(character.getSprite());
        window.display();
    }
    return 0;
}