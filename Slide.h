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
    explicit Slide(const char* path);
    Slide(const Slide&);
    ~Slide();
    sf::Sprite* getSprite() const;
};


#endif //CREATIVESLIDES_SLIDE_H
