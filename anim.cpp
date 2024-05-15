#include <SFML/Graphics.hpp>
//PER TASTIERA
class Character {
public:
    Character(const std::string& textureFile) {
        if (!texture.loadFromFile(textureFile)) {
            // Handle error...
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); // Set initial frame
    }

    void move(float dx, float dy) {
        sprite.move(dx, dy);

        // Update the frame for walking animation
        if (moveCount % 450 == 0) { 
            frame = (frame + 1) % 4;
        }
        moveCount++;
        if (dx > 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 128, 64, 64)); // Right walking animation
        } else if (dx < 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 64, 64, 64)); // Left walking animation
        } else if (dy > 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 0, 64, 64)); // Down walking animation
        } else if (dy < 0) {
            sprite.setTextureRect(sf::IntRect(frame * 64, 192, 64, 64)); // Up walking animation
        }
    }

    sf::Sprite& getSprite() {
        return sprite;
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    int frame = 0; // Current frame for animation
    int moveCount=0;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Keyboard");
    Character character("pokemon.png"); // Replace with your sprite sheet file

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int frame=0;
        int movecount=0;

        // Check for keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            character.move(0, -0.1); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            character.move(0, 0.1); // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            character.move(-0.1, 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            character.move(0.1, 0); // Move right
        }

        window.clear();
        window.draw(character.getSprite());
        window.display();
    }

    return 0;
}