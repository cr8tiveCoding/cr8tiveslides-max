#ifndef CREATIVESLIDES_SLIDE_H
#define CREATIVESLIDES_SLIDE_H


#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Slide {
private:
    sf::Texture* texture;
    sf::Sprite* sprite;
public:
    Slide(const char* path);
    sf::Sprite* getSprite() const;
};


#endif //CREATIVESLIDES_SLIDE_H
