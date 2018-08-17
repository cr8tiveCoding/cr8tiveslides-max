#ifndef CREATIVESLIDES_FUNCTIONS_H
#define CREATIVESLIDES_FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void setSpriteSize(sf::Sprite& sprite, sf::Vector2f target) {
    auto size = static_cast<sf::Vector2f>(sprite.getTexture()->getSize());
    sprite.setScale(target.x/size.x, target.y/size.y);
}

#endif //CREATIVESLIDES_FUNCTIONS_H
