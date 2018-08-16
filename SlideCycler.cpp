#include <iostream>
#include "SlideCycler.h"

SlideCycler::SlideCycler(SlideCache const *slides, sf::RenderWindow *renderWindow, float secondsPer) {
    cache = slides;
    window = renderWindow;
    this->secondsPer = secondsPer;
    slideNumber = 0;
}

void SlideCycler::tick() {
    if (clock.getElapsedTime().asSeconds() >= secondsPer) {
        slideNumber = (slideNumber + 1) % cache->size();
        clock.restart();
    }
    window->draw(*cache->getSlide(slideNumber)->getSprite());
}




