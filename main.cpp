#include <iostream>
#include <SFML/Graphics.hpp>

void setSize(sf::Sprite& sprite, sf::Vector2f target) {
    sf::Vector2f size = (sf::Vector2f) sprite.getTexture()->getSize();
    sprite.setScale(target.x/size.x, target.y/size.y);
}

int main() {

    unsigned int w = sf::VideoMode::getDesktopMode().width,
                 h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Slides", sf::Style::Fullscreen);
    window.setPosition(sf::Vector2i(0, 0));
    sf::Image staticImage;
    sf::Texture texture;
    sf::Sprite imageSprite;

    if(!staticImage.loadFromFile("images/bravo.jpg")) {
        std::exit(1);
    }

    texture.loadFromImage(staticImage);
    imageSprite.setTexture(texture);

    setSize(imageSprite, sf::Vector2f(w, h));

    while (window.isOpen()) {
        sf::Event event = {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear(sf::Color::Blue);

        window.draw(imageSprite);

        window.display();
    }

    return 0;
}