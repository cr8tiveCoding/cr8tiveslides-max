#include "Slide.h"
#include "Functions.h"

Slide::Slide(const char* path) {
    sf::Image image;
    if (!image.loadFromFile(path)) {
        std::exit(1);
    }
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    texture->loadFromImage(image);
    sprite->setTexture(*texture);
    setSpriteSize(*sprite, sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
}

sf::Sprite* Slide::getSprite() const {
    return sprite;
}
