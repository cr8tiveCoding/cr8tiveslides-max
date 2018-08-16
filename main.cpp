#include <iostream>
#include <SFML/Graphics.hpp>
#include "SlideCache.h"


int main() {

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Slides", sf::Style::Fullscreen);
    window.setPosition(sf::Vector2i(0, 0));

    SlideCache slides("images/");

    while (window.isOpen()) {
        sf::Event event = {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear(sf::Color::Blue);

        window.draw(*slides.getSlide(0)->getSprite());

        window.display();
    }

    return 0;
}