#include <iostream>
#include <SFML/Graphics.hpp>
#include "SlideCache.h"
#include "SlideCycler.h"


int main() {

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Slides", sf::Style::None);
    window.setPosition(sf::Vector2i(0, 0));

    SlideCache slides("images/");
    SlideCycler cycler(&slides, &window, 1.5);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event = {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        cycler.tick();
        window.display();
    }

    return 0;
}