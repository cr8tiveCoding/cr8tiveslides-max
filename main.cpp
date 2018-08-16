#include <iostream>
#include <SFML/Graphics.hpp>
#include "SlideCache.h"


int main() {

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Slides", sf::Style::Fullscreen);
    window.setPosition(sf::Vector2i(0, 0));

    SlideCache slides("images/");

    sf::Clock clock;
    for (int i = 0; window.isOpen();) {
        sf::Event event = {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear(sf::Color::Blue);
        if (clock.getElapsedTime().asSeconds() >= 1.5) {
            i = (i + 1) % slides.size();
            clock.restart();
        }
        window.draw(*slides.getSlide(i)->getSprite());

        window.display();
    }

    return 0;
}